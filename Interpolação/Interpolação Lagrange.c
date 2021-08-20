#include <stdio.h>

void interpolacaoLagrange(int n, double x[n], double y[n], double xi) {
    double yi = 0;
    
    for (int i = 0; i < n; i++) {
        double L = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            L *= (xi - x[j])/(x[i] - x[j]);
        }
        yi += y[i] * L;
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
    printf("Insira o ponto a ser interpolado: ");
    scanf("%lf", &xi);
    
    interpolacaoLagrange(n, x, y, xi);
    
    return 0;
}
