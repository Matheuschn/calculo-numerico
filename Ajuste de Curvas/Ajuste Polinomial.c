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
    x = (double*) calloc(n,sizeof(double));
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

void ajustePolinomial(int n, int m, double x[n], double y[n]) {
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
    
    for (int i = 0; i < m; i++) {
        printf("S[%d] = %lf \n", i, *(S + i));
    }
}

int main() {
    int n, m;
    printf("Insira o grau de ajuste polinomial: ");
    scanf("%d", &m);
    printf("Insira o número de pontos: ");
    scanf("%d", &n);
    
    double x[n], y[n];
    for (int i = 0; i < n; i++) {
        printf("Insira o ponto %d, com X e Y separados por espaço: ", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    
    ajustePolinomial(n, m + 1, x, y);
    
    return 0;
}
