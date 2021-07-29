#include <math.h>
#include <stdio.h>

void print(int i, double x, double fout, int digits) {
    printf("Iterações: %d\n", i);
    printf("Raiz: %.*lf\n", digits, x);
    printf("Precisao: %g\n", fout);
}

double function(double x) {
    return exp(x) - (2 * cos(x));
}

double derivative(double x) {
    return exp(x) + (2 * sin(x));
}

void newton(double x, double error) {
    int i = 0;
    
    do {
        i++;
        x = x - (function(x)/derivative(x));
    } while (error < fabs(function(x)));
    
    print(i, x, function(x), 10);
}

int main() {
    double x, error;
    printf("Insira o ponto x0: ");
    scanf("%lf", &x);
    printf("Insira o erro: ");
    scanf("%lf", &error);
    newton(x, error);
    
    return 0;
}