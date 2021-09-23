#include <stdio.h>

double f(double x, double y) {
    return (y * x * x) - y;
}

void euler(double x0, double y0, double x1, double x2, double h) {
    double y = y0;
    double x = x0;
    int i = 1;
    
    do {
        x = x0 + (i - 1) * h;
        y = y + (h * f(x, y));
        printf("\tx = %lf, y%d = %lf\n", x + h, i, y);
        i++;
    } while((x2 - x1)/h >= i);
}

void rungeKutta(double x0, double y0, double x1, double x2, double h, int n) {
    double y = y0;
    double x = x0;
    double k[n];
    int i = 1;
    
    do {
        x = x0 + (i - 1) * h;
        
        k[0] = h * f(x, y);
        if (n == 2) {
            k[1] = h * f(x + h, y + k[0]);
            y = y + (k[0] + k[1])/2;
        } else if (n == 4) {
            k[1] = h * f(x + h/2, y + k[0]/2);
            k[2] = h * f(x + h/2, y + k[1]/2);
            k[3] = h * f(x + h, y + k[2]);
            y = y + (k[0] + 2 * k[1] + 2 * k[2] + k[3])/6;
        }

        printf("\n\tx = %lf, y%d = %lf\n", x + h, i, y);
        for (int j = 0; j < n; j++) {
            printf("\tk[%d] = %lf\n", j + 1, k[j]);
        }

        i++;
    } while((x2 - x1)/h >= i);
}

int main() {
    double x1, x2;
    printf("Insira o intervalo de x separado por espaço: ");
    scanf("%lf %lf", &x1, &x2);
    
    double x0, y0;
    printf("Insira o valor de x0: ");
    scanf("%lf", &x0);
    printf("Insira o valor de y no ponto x0: ");
    scanf("%lf", &y0);
    
    double h;
    printf("Insira o valor de h: ");
    scanf("%lf", &h);
    
    printf("\nMétodo de Euler:\n");
    euler(x0, y0, x1, x2, h);
    
    printf("\nMétodo de Runge-Kutta, segunda ordem:");
    rungeKutta(x0, y0, x1, x2, h, 2);
    printf("\nMétodo de Runge-Kutta, quarta ordem:");
    rungeKutta(x0, y0, x1, x2, h, 4);
    
    return 0;
}
