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

void bisection(double a, double b, double error) {
    double averageX;
    double result, resultA, resultB;
    int i = 0;
    
    do {
        i++;
        averageX = (a + b)/2.0;
        
        result = function(averageX);
        resultA = function(a);
        resultB = function(b);
        
        if (error > fabs(result)) {
            break;
        } else if ((resultA * result) > 0) {
            a = averageX;
        } else {
            b = averageX;
        }
    } while(fabs(result) >= error);
    
    print(i, averageX, result, 10);
}

int main() {
    double a, b, error;
    printf("Insira o ponto a: ");
    scanf("%lf", &a);
    printf("Insira o ponto b: ");
    scanf("%lf", &b);
    printf("Insira o erro: ");
    scanf("%lf", &error);
    
    bisection(a, b, error);
    
    return 0;
}
