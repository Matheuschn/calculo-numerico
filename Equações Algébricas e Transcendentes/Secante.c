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

void secante(double x0, double x1, double error) {
    double x2, f0, f1, f2;
    int i = 0;
    do {
        i++;

        f0 = function(x0);
        f1 = function(x1);
    	
        x2 = x1 - (x1 - x0) * f1/(f1-f0);
        f2 = function(x2);
    	  
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
    } while(fabs(f2) > error);
    
    print(i, x2, fabs(f2), 10);
}

int main() {
    double x0, x1, error;
    printf("Insira o ponto x0: ");
    scanf("%lf", &x0);
    printf("Insira o ponto x1: ");
    scanf("%lf", &x1);
    printf("Insira o erro: ");
    scanf("%lf", &error);
    secante(x0, x1, error);
    
    return 0;
}
