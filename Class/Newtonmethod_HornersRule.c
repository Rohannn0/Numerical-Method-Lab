/* Newton's Method and Horner's Rule */
#include<stdio.h>

int main()
{
    int n,i,j,iter;
    float x,p,dp;

    printf("Enter degree of polynomial: ");
    scanf("%d",&n);

    float a[n+1];

    printf("Enter coefficients (highest degree to constant):\n");
    for(i=0;i<=n;i++)
        scanf("%f",&a[i]);

    printf("Enter value of x for Horner evaluation: ");
    scanf("%f",&x);

    /* Horner's Rule Evaluation */
    p=a[0];
    dp=0;

    for(j=1;j<=n;j++)
    {
        dp=dp*x+p;
        p=p*x+a[j];
    }

    printf("\nUsing Horner's Rule:\n");
    printf("Polynomial value f(x) = %.4f\n",p);
    printf("Derivative value f'(x) = %.4f\n",dp);

    printf("\nEnter initial guess for Newton Method: ");
    scanf("%f",&x);

    printf("Enter number of iterations: ");
    scanf("%d",&iter);

    printf("\nNewton Method Iterations:\n");

    for(i=1;i<=iter;i++)
    {
        p=a[0];
        dp=0;

        for(j=1;j<=n;j++)
        {
            dp=dp*x+p;
            p=p*x+a[j];
        }

        x=x-p/dp;

        printf("Iteration %d Root = %.6f\n",i,x);
    }

    printf("\nApproximate Root = %.6f\n",x);

    return 0;
}