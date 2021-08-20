#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double * gaussSemPivo(int n, double a[n][n], double b[n]) {
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double ratio = a[i][k]/a[k][k];
            for (int j = k; j < n; j++) {
                a[i][j] = a[i][j] - (ratio * a[k][j]);
            }
            b[i] = b[i] - (ratio * b[k]);
        }
    }
    
    static double * x;
    x = (double*) calloc(n, sizeof(double));
    x[n - 1] = b[n - 1]/a[n - 1][n - 1];
    
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (1/a[i][i])*(b[i] - sum);
    }
    
    return x;
} 

void ajusteNaoPolinomial(int n, int tipo, double x[n], double y[n]) {
    if (tipo != 3) {
        for (int i = 0; i < n; i++) {
            y[i] = log(y[i]);
        }
    } else {
        for (int i = 0; i < n; i++) {
            x[i] = log(x[i]);
            Z[i] = y[i];
        }
    }
    
    int m = 2;
    double C[m][m];
    double D[m];
    double * S;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += pow(x[k], j + i);
            }
        }
        for (int k = 0; k < n; k++) {
            D[i] += y[k] * pow(x[k], i);
        }
    }
    
    S = gaussSemPivo(m, C, D);
    double a = *(S);
    double b = *(S + 1);
    
    switch (tipo) {
        case 1:
            a = exp(a);
            printf("y = %lf * e^(%lf * x)\n", a, b);
        break;
        
        case 2:
            a = exp(a);
            b = exp(b);
            printf("y = %lf * %lf^x\n", a, b);
        break;
        
        case 3:
            printf("y = %lf * log(x) %+lf\n", b, a);
        break;
        
        case 4:
            a = exp(a);
            printf("y = %lf * x^%lf\n", a, b);
        break;
    }
}

int main() {
    int tipo, n;
    printf("1 - Ajuste exponencial (a * e^bx)\n2 - Ajuste exponencial (a * b^x)\n"
    "3 - Ajuste logaritmico (a * log(x) - b)\n4 - Ajuste geométrico (a * x^b)\n");

    printf("Digite o número associado com o tipo do ajuste não polinomial: ");
    scanf("%d", &tipo);
    if (tipo < 1 || tipo > 4) return 1;

    printf("Insira o número de pontos: ");
    scanf("%d", &n);
    
    double x[n], y[n];
    for (int i = 0; i < n; i++) {
        printf("Insira o ponto %d, com X e Y separados por espaço: ", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    
    ajusteNaoPolinomial(n, tipo, x, y);
    
    return 0;
}
