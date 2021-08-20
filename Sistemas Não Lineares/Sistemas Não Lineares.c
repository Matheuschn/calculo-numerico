#include <math.h>
#include <stdio.h>
#include <string.h>

double f0(double x[]) {
    return x[0]*x[1] - 1;
}

double f1(double x[]) {
    return x[0] - exp(x[1]);
}

typedef double (*function)(double []);
function f[] = {&f0, &f1};

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

double * gaussSemPivo(int n, double a[n][n], double b[n]) {
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double ratio = a[i][k]/a[k][k];
            for (int j = k; j < n; j++) {
                a[i][j] = a[i][j] - (ratio * a[k][j]);
            }
            b[i] = b[i] - (ratio * b[k]);
        }
    }
    
    static double * x;
    x = (double*) calloc(n, sizeof(double));
    x[n - 1] = b[n - 1]/a[n - 1][n - 1];
    
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (1/a[i][i])*(b[i] - sum);
    }
    
    double r[n];
    for (int i = 0; i < n; i++) {
        r[i] = -(b[i]);
        for (int j = 0; j < n; j++) {
            r[i] += a[i][j] * x[j];
        }
    }
    return x;
}

double derivative(int j, int d, int n, double h, double x[n]) {
    double y[n];
    memcpy(y, x, sizeof(y));
    y[d] = x[d] + h;
    return (f[j](y) - f[j](x))/h;
}

void nonLinear(int n, int i, double h, double x[n]) {
    double J[n][n];
    double F[n];
    double * S;
    
    for (i; i > 0; i--) {
        for (int y = 0; y < n; y++) {
            F[y] = -(f[y](x));
            for (int k = 0; k < n; k++) {
                J[y][k] = derivative(y, k, n, h, x);
            }
        }
        S = gaussSemPivo(n, J, F);
        for (int j = 0; j < n; j++) {
            x[j] = *(S + j) + x[j];
        }
    }
    printVector(n, x, "Solução");
}

int main() {
    int n = sizeof f / sizeof *f;
    int i;
    printf("Insira o número de iterações: ");
    scanf("%d", &i);
    double h;
    printf("Insira o h: ");
    scanf("%lf", &h);
    double x[n];
    for (int j = 0; j < n; j++) {
        printf("Insira o ponto x%d: ", j);
        scanf("%lf", &x[j]);
    }
    nonLinear(n, i, h, x);
    
    return 0;
}
