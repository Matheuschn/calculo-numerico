#include <math.h>
#include <stdio.h>
#include <complex.h>

void print(int i, complex double x, complex double R, int digits) {
    printf("Iterações: %d\n", i);
    printf("Raiz: %.*lf %+.*lfi\n", digits, creal(x), digits, cimag(x));
    printf("Conjugado: %.*lf %+.*lfi\n", digits, creal(x), digits, -cimag(x));
    printf("Precisao: %g\n", cabs(R));
}

void birgeVieta(int n, double a[], complex double x0, double error) {
    complex double b[(n + 1) * 2], c[n * 2];
    complex double R, R1, out, fout;
    int i = 0;
    
    do {
        i++;
        for (int j = 0; j <= n; j++) {
            b[j] = a[j] + b[j - 1] * x0;
        }
        R = b[n];
        
        for (int j = 0; j < n; j++) {
            c[j] = b[j] + c[j - 1] * x0;
        }
        R1 = c[n - 1];

        out = x0 - R/R1;
        x0 = out;
    } while(cabs(R) > error);
    
    print(i, x0, R, 20);
}

int main() {
    int n;
    complex double x0;
    double error, real, imag;
    printf("Insira a parte real de x0: ");
    scanf("%lf", &real);
    printf("Insira a parte imaginária de x0: ");
    scanf("%lf", &imag); 
    x0 = CMPLX(real, imag);
    printf("Insira o erro: ");
    scanf("%lf", &error);
    printf("Insira o grau do polinômio (maior que 2): ");
    scanf("%d", &n);
    double a[n + 1];
    for (int i = 0; i <= n; i++) {
        printf("Insira o coeficiente a%d: ", i);
        scanf("%lf", &a[i]);
    }
    
    birgeVieta(n, a, x0, error);

    return 0;
}
