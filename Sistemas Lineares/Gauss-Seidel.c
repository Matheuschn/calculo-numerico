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

void gaussSeidel(int n, double a[n][n], double b[n], double error) {
    double newx, x[n], absdiff[n], reldiff[n], r[n];
    double maxabs, maxrel, maxr;
    do {
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += a[i][j] * x[j];
            }
            for (int j = i + 1; j < n; j++) {
                sum += a[i][j] * x[j];
            }
            newx = (b[i] - sum)/a[i][i];
            absdiff[i] = fabs(newx - x[i]);
            reldiff[i] = fabs((newx - x[i])/newx);
            x[i] = newx;
            double rsum = 0;
            for (int j = 0; j < n; j++) {
                rsum += a[i][j] * x[j];
            }
            r[i] = b[i] - rsum;
        }
        maxabs = 0;
        maxrel = 0;
        maxr = 0;
        for (int i = 0; i < n; i++) {
            if (absdiff[i] > maxabs)  {
                maxabs = absdiff[i];
            }
            if (reldiff[i] > maxrel) {
                maxrel = reldiff[i];
            }
            if (r[i] > maxr)  {
                maxr = r[i];
            }
        }
    } while ((maxabs > error) || (maxrel > error) || (maxr > error));
    
    printArray(n, a, "A");
    printVector(n, b, "B");
    printVector(n, x, "solução");
    printVector(n, r, "resíduo");
} 

int main() {
    int n;
    printf("Insira o número de coeficientes: ");
    scanf("%d", &n);
    double error;
    printf("Insira o erro: ");
    scanf("%lf", &error);
    double x[n];
    for (int i = 0; i < n; i++) {
        printf("Insira o valor inicial da linha %d: ", i + 1);
        scanf("%lf", &x[i]);
    }
    
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

    gaussSeidel(n, a, b, error); 
    
    return 0;
}