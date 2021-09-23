#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1/x;
}

void quadratura(double a, double b, int n) {
    const double t[4][4] = {
        {0, 0, 0, 0},
        {(-1)/(sqrt(3)), (1)/(sqrt(3)), 0, 0},
        {0.77459667, -0.77459667, 0, 0},
        {0.86113631, -0.86113631, 0.33998104, -0.33998104}
    };
    const double A[4][4] = {
        {2, 0, 0, 0},
        {1, 1, 0, 0},
        {0.55555555, 0.55555555, 0.88888888, 0},
        {0.34785484, 0.34785484, 0.65214516, 0.65214516}
    };
    
    double tFactor[2] = {(b - a)/2, (b + a)/2};
    double dt = tFactor[0];
    
    double result;
    for (int i = 0; i < n; i++) {
        result += A[n - 1][i] * f((tFactor[0] * t[n - 1][i]) + tFactor[1]) * dt;
    }
    
    printf("Resultado: %lf\n", result);
}

int main() {
    double a, b;
    printf("Insira o valor de a e b: ");
    scanf("%lf %lf", &a, &b);
    
    int n;
    printf("Insira o valor de n: ");
    scanf("%d", &n);
    
    quadratura(a, b, n);
    
    return 0;
}
