#include <stdio.h>
#include <math.h>
#include <string.h>

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

void printIntVector(int n, int vector[n], char* name) {
    printf("\n\n Vetor %s = \n\t", name);
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
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

void gaussPivoParcialSemTroca(int n, double a[n][n], double b[n]) {
    double c[n][n], d[n];
    memcpy(c, a, sizeof(c));
    memcpy(d, b, sizeof(d));
    
    int o[n];
    for (int i = 0; i < n; i++) {
        o[i] = i;
    }
    
    for (int k = 0; k < n - 1; k++) {
        int pivot = 0;
        double max = 0;
        for (int i = k; i < n; i++) {
            if (fabs(a[o[i]][k]) > max) {
                pivot = i;
                max = fabs(a[o[i]][k]);
            }
        }
        int temp = o[k];
        o[k] = o[pivot];
        o[pivot] = temp;

        for (int i = k + 1; i < n; i++) {
            double ratio = a[o[i]][k]/a[o[k]][k];
            for (int j = k; j < n; j++) {
                a[o[i]][j] = a[o[i]][j] - (ratio * a[o[k]][j]);
            }
            b[o[i]] = b[o[i]] - (ratio * b[o[k]]);
        }
    }
    
    double x[n];
    x[n - 1] = b[o[n - 1]]/a[o[n - 1]][n - 1];
    
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += a[o[i]][j] * x[j];
        }
        x[i] = (1/a[o[i]][i])*(b[o[i]] - sum);
    }
    
    double r[n];
    for (int i = 0; i < n; i++) {
        r[i] = -(d[i]);
        for (int j = 0; j < n; j++) {
            r[i] += c[i][j] * x[j];
        }
    }
    
    printArray(n, a, "A");
    printVector(n, b, "B");
    printVector(n, x, "solução");
    printIntVector(n, o, "ordenamento");
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
    }
    
    gaussPivoParcialSemTroca(n, a, b); 
    
    return 0;
}