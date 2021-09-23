#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(x) + 2*x;
}

void trapezio(double a, double b, int n) {
    double h = (b - a)/n;
    double sum;
    
    for (int i = 1; i < n; i++) {
        double xi = a + (i * h);
        sum += f(xi);
    }
    
    double result = (h/2) * (f(a) + (2 * sum) + f(b));
    
    printf("Resultado (Trapézio): %lf\n", result);
}

void simpson(double a, double b, int n) {
    double h = (b - a)/n;
    double firstSum, secondSum;
    
    for (int i = 1; i <= (n/2); i++) {
        double xi = a + (((2 * i) - 1) * h);
        firstSum += f(xi);
    }
    
    for (int i = 1; i < (n/2); i++) {
        double xi = a + ((2 * i) * h);
        secondSum += f(xi);
    }
    
    double result = (h/3) * (f(a) + (4 * firstSum) + (2 * secondSum) + f(b));
    
    printf("Resultado (Simpson): %lf\n", result);
}

int main() {   
    double a, b;
    printf("Insira o valor de a e b: ");
    scanf("%lf %lf", &a, &b);
    
    int n;
    printf("Insira o valor de n: ");
    scanf("%d", &n);
    
    trapezio(a, b, n);
    simpson(a, b, n);
    
    return 0;
}
