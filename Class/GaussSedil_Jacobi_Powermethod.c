/* Jacobi, Gauss-Seidel, and Power Method */
#include <stdio.h>
#include <math.h>

#define MAX 10

// Function to perform Jacobi Method
void jacobi(int n, float a[MAX][MAX], float b[MAX], int iter, float tol) {
    float x[MAX], x_new[MAX];
    int i,j,k;
    for(i=0;i<n;i++) x[i]=0; // initial guess

    printf("\nJacobi Iterations:\n");
    for(k=1;k<=iter;k++) {
        for(i=0;i<n;i++) {
            x_new[i] = b[i];
            for(j=0;j<n;j++) {
                if(j!=i) x_new[i] -= a[i][j]*x[j];
            }
            x_new[i] /= a[i][i];
        }

        printf("Iteration %d: ", k);
        for(i=0;i<n;i++) printf("x%d=%.6f ",i+1,x_new[i]);
        printf("\n");

        // Check tolerance
        float max_diff=0;
        for(i=0;i<n;i++) {
            float diff = x_new[i]-x[i];
            if(diff<0) diff=-diff;
            if(diff>max_diff) max_diff=diff;
        }
        if(max_diff<tol) break;

        for(i=0;i<n;i++) x[i]=x_new[i];
    }
}

// Function to perform Gauss-Seidel Method
void gauss_seidel(int n, float a[MAX][MAX], float b[MAX], int iter, float tol) {
    float x[MAX];
    int i,j,k;
    for(i=0;i<n;i++) x[i]=0; // initial guess

    printf("\nGauss-Seidel Iterations:\n");
    for(k=1;k<=iter;k++) {
        for(i=0;i<n;i++) {
            float sum = b[i];
            for(j=0;j<n;j++) {
                if(j!=i) sum -= a[i][j]*x[j];
            }
            x[i]=sum/a[i][i];
        }

        printf("Iteration %d: ", k);
        for(i=0;i<n;i++) printf("x%d=%.6f ",i+1,x[i]);
        printf("\n");

        // No explicit tolerance check here (can be added if needed)
    }
}

// Function to perform Power Method
void power_method(int n, float a[MAX][MAX], int iter, float tol) {
    float x[MAX], x_new[MAX];
    int i,j,k;
    float lambda=0, lambda_old;

    for(i=0;i<n;i++) x[i]=1; // initial guess vector

    printf("\nPower Method Iterations:\n");
    for(k=1;k<=iter;k++) {
        // Multiply matrix by vector
        for(i=0;i<n;i++) {
            x_new[i]=0;
            for(j=0;j<n;j++) x_new[i]+=a[i][j]*x[j];
        }

        // Find maximum element for dominant eigenvalue
        lambda_old = lambda;
        lambda=0;
        for(i=0;i<n;i++) {
            if(fabs(x_new[i])>fabs(lambda)) lambda=x_new[i];
        }

        // Normalize vector
        for(i=0;i<n;i++) x[i]=x_new[i]/lambda;

        printf("Iteration %d: Eigenvalue=%.6f, Vector=[", k, lambda);
        for(i=0;i<n;i++) printf("%.6f ", x[i]);
        printf("]\n");

        if(fabs(lambda-lambda_old)<tol) break;
    }

    printf("\nApproximate dominant eigenvalue = %.6f\n", lambda);
}

int main() {
    int choice,n,i,j,iter;
    float tol;
    float a[MAX][MAX],b[MAX];

    printf("Choose Method:\n1. Jacobi\n2. Gauss-Seidel\n3. Power Method\n");
    scanf("%d",&choice);

    printf("Enter size of matrix (n): ");
    scanf("%d",&n);

    printf("Enter number of iterations: ");
    scanf("%d",&iter);

    printf("Enter tolerance (e.g., 0.0001): ");
    scanf("%f",&tol);

    printf("Enter matrix A elements row-wise:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%f",&a[i][j]);

    if(choice==1 || choice==2) {
        printf("Enter RHS vector b:\n");
        for(i=0;i<n;i++)
            scanf("%f",&b[i]);
    }

    switch(choice) {
        case 1: jacobi(n,a,b,iter,tol); break;
        case 2: gauss_seidel(n,a,b,iter,tol); break;
        case 3: power_method(n,a,iter,tol); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}