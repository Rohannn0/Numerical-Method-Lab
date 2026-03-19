/* Iteration Method */
#include<stdio.h>
#include<math.h>

float g(float x)
{
    return pow((2*x+5),1.0/3);
}

int main()
{
    float x0,x1;
    int i,n;

    printf("Enter initial guess: ");
    scanf("%f",&x0);

    printf("Enter number of iterations: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        x1 = g(x0);
        printf("Iteration %d  Root = %f\n",i,x1);
        x0 = x1;
    }

    printf("Approximate root = %f",x1);
}