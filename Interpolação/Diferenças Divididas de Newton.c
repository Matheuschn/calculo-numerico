#include <stdio.h>

void diferencasDivididas(int n, double x[n], double y[n], double xi) {
    double o[n][n];
    
    for (int i = 0; i < n; i++) {
        o[i][0] = y[i];
    }
    
    for (int j = 1; j < n; j++) {
        for (int i = j; i < n; i++) {
            o[i][j] = (o[i][j - 1] - o[i - 1][j - 1])/(x[i] - x[i - j]);
        }
    }
    
    double b[n];
    double P;
    for (int j = 0; j < n; j++) {
        b[j] = 1;
        for (int i = 0; i < j; i++) {
            b[j] *= xi - x[i];
        }

        P += o[j][j] * b[j];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("o[%d][%d] = %lf\n", i, j, o[i][j]);
        }
    }

    printf("P(%lf) = %lf\n", xi, P);
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
    printf("Insira o ponto a ser interpolado: ");
    scanf("%lf", &xi);
    
    diferencasDivididas(n, x, y, xi);
    
    return 0;
}
