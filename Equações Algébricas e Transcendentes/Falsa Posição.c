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

void falsePosition(double a, double b, double error) {
    double averageX;
    double result, resultA, resultB;
    int i = 0;
    
    while(fabs(b - a) >= error) {
        i++;
        
        resultA = function(a);
        resultB = function(b);
        averageX = a - (resultA*(b - a))/(resultB - resultA);
        result = function(averageX);
        
        if (fabs(result) < error) {
            break;
        } else if ((resultA * result) > 0) {
            a = averageX;
        } else {
            b = averageX;
        }
    }
    
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
    
    falsePosition(a, b, error);
    
    return 0;
}
