#include <stdio.h>
#include <math.h>

void printVector(int n, double vector[n], char* name) {
    int max = n < 6 ? n : 6;
    printf("\n\n Vetor %s = \n", name);
    printf("\tColumns 1 through %d:\n\n\t", max);
    for (int i = 0; i < max; i++) {
        printf("%lf ", vector[i]);
    }
    if (n > max) {
        printf("\n\n\tColumns 7 through %d:\n\t", n);
        for (int i = max; i < n; i++) {
            printf("%lf ", vector[i]);
        }
    }
}

void gaussTridiagonal(int n, double d[n - 1], double r[n], double t[n - 1], double b[n]) {
    for (int i = 1; i < n; i++) {
        double mult = t[i - 1]/r[i - 1];
        r[i] = r[i] - (mult * d[i - 1]);
        b[i] = b[i] - (mult * b[i - 1]);
    }
    
    double x[n];
    x[n - 1] = b[n - 1]/r[n - 1];
    
    for (int i = n - 2; i >= 0; i--) {
        x[i] = (b[i] - (d[i] * x[i + 1]))/r[i];
    }
    
    printVector(n - 1, d, "D");
    printVector(n, r, "R");
    printVector(n - 1, t, "T");
    printVector(n, b, "B");
    printVector(n, x, "solução");
} 

int main() {
    int n;
    printf("Insira o número de coeficientes: ");
    scanf("%d", &n);
    
    double d[n - 1], r[n], t[n - 1], b[n];

    for (int i = 0; i < n - 1; i++) {
        printf("Insira o coeficiente D da linha %d: ", i + 1);
        scanf("%lf", &d[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("Insira o coeficiente R da linha %d: ", i + 1);
        scanf("%lf", &r[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        printf("Insira o coeficiente T da linha %d: ", i + 2);
        scanf("%lf", &t[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("Insira o coeficiente B da linha %d: ", i + 1);
        scanf("%lf", &b[i]);
    }

    gaussTridiagonal(n, d, r, t, b); 
    
    return 0;
}