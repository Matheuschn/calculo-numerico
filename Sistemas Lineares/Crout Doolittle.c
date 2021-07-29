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

void printArray(int n, double array[n][n], char* name) {
    int max = n < 6 ? n : 6;
    printf("\n\nMatriz %s = \n", name);
    printf("\tColumns 1 through %d:\n\n\t", max);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < max; j++) {
            printf("%lf ", array[i][j]);
        }
        printf("\n\t");
    }
    if (n > max) {
        printf("\n\tColumns 7 through %d:\n\n\t", n);
        for (int i = 0; i < n; i++) {
            for (int j = max; j < n; j++) {
                printf("%lf ", array[i][j]);
            }
            printf("\n\t");
        }    
    }
}

void croutDoolittle(int n, double a[n][n], double b[n]) {
    double l[n][n], u[n][n];
    for (int i = 0; i < n; i++) {
        u[i][i] = 1.0;
        for (int j = 0; j < n; j++) {
            l[i][j] = 0;
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = k; i < n; i++) {
            double sum = 0;
            for (int r = 0; r <= k - 1; r++) {
                sum += l[i][r] * u[r][k];
            }
            l[i][k] = a[i][k] - sum;
        }
        
        for (int j = k + 1; j < n; j++) {
            double sum = 0;
            for (int r = 0; r <= k - 1; r++) {
                sum += l[k][r] * u[r][j];
            }
            u[k][j] = (1/l[k][k]) * (a[k][j] - sum);
        }
    }
    
    double y[n];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int r = 0; r <= i - 1; r++) {
            sum += l[i][r] * y[r];
        }
        y[i] = (1/l[i][i]) * (b[i] - sum);
    }
    
    double x[n];
    x[n - 1] = y[n - 1];
    
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += u[i][j] * x[j];
        }
        x[i] = y[i] - sum;
    }
    
    double r[n];
    for (int i = 0; i < n; i++) {
        r[i] = -(b[i]);
        for (int j = 0; j < n; j++) {
            r[i] += a[i][j] * x[j];
        }
    }
    
    printArray(n, a, "A");
    printVector(n, b, "B");
    printArray(n, l, "L");
    printArray(n, u, "U");
    printVector(n, y, "Y");
    printVector(n, x, "solução");
    printVector(n, r, "resíduo");
} 

int main() {
    int n;
    printf("Insira o número de coeficientes: ");
    scanf("%d", &n);
    double a[n][n];
    double b[n];
    for (int i = 0; i < n; i++) {
        printf("Insira os coeficientes da linha %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &a[i][j]);   
        }
    }
    for (int i = 0; i < n; i++) {
        printf("Insira o coeficiente B da linha %d: ", i + 1);
        scanf("%lf", &b[i]);
    
    croutDoolittle(n, a, b); 
    
    return 0;
}