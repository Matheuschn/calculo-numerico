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

void interpolacaoPolinomial(int n, double x[n], double y[n], double xi) {
    double v[n][n];
    double * a;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = pow(x[i], j);
        }
    }
    
    a = gaussSemPivo(n, v, y);

    for (int i = 0; i < n; i++) {
        printf("a[%d] = %lf\n", i, *(a + i));
    }
    double yi = 0;
    for (int i = 0; i <= n; i++) {
        yi += *(a + i) * pow(xi, i);
    }
    printf("f(%lf) = %lf\n", xi, yi);
}

int main() {
    int n;
    printf("Insira o número de pontos: ");
    scanf("%d", &n);
    
    double x[n], y[n];
    for (int i = 0; i < n; i++) {
        printf("Insira o ponto %d, com X e Y separados por espaço: ", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    
    double xi;
    printf("Caso deseje, insira o ponto a ser interpolado: ");
    scanf("%lf", &xi);
    
    interpolacaoPolinomial(n, x, y, xi);
    
    return 0;
}
