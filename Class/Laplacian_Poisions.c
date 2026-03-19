#include <stdio.h>

#define N 5

int main() {
    int i,j,k,choice;
    float u[N][N]={0}, f[N][N]={0};

    printf("1. Laplace Equation\n");
    printf("2. Poisson Equation\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    // Boundary conditions
    for(i=0;i<N;i++){
        u[0][i]=100;
        u[N-1][i]=100;
        u[i][0]=100;
        u[i][N-1]=100;
    }

    if(choice==2)
        f[2][2]=10;   // source term only for Poisson

    for(k=0;k<10;k++)
        for(i=1;i<N-1;i++)
            for(j=1;j<N-1;j++)
                u[i][j]=0.25*(u[i+1][j]+u[i-1][j]+u[i][j+1]+u[i][j-1]-f[i][j]);

    printf("\nSolution:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%6.2f ",u[i][j]);
        printf("\n");
    }

    return 0;
}