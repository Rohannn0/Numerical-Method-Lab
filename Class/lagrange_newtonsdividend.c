/* Lagrange Interpolation and Newton Divided Difference */
#include<stdio.h>

int main()
{
    int i,j,n,choice;
    float x;

    printf("Enter number of data points: ");
    scanf("%d",&n);

    float X[n],Y[n],a[n][n];

    printf("Enter values of X:\n");
    for(i=0;i<n;i++)
        scanf("%f",&X[i]);

    printf("Enter values of Y:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&Y[i]);
        a[i][0] = Y[i]; // first column for divided differences
    }

    printf("Enter value of x: ");
    scanf("%f",&x);

    printf("\nChoose Method:\n");
    printf("1. Lagrange Interpolation\n");
    printf("2. Newton Divided Difference\n");
    scanf("%d",&choice);

    if(choice==1)
    {
        // Lagrange Interpolation
        float y=0,p;

        for(i=0;i<n;i++)
        {
            p=1;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                    p=p*(x-X[j])/(X[i]-X[j]);
            }
            y=y+p*Y[i];
        }

        printf("\nInterpolated value using Lagrange = %.2f\n",y);
    }
    else if(choice==2)
    {
        // Newton Divided Difference Table
        for(j=1;j<n;j++)
        {
            for(i=0;i<n-j;i++)
            {
                a[i][j] = (a[i+1][j-1]-a[i][j-1])/(X[i+j]-X[i]);
            }
        }

        // Print Divided Difference Table
        printf("\nDivided Difference Table:\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i;j++)
                printf("%10.4f",a[i][j]);
            printf("\n");
        }

        // Calculate interpolated value
        float sum=a[0][0],term=1;
        for(i=1;i<n;i++)
        {
            term = term*(x-X[i-1]);
            sum = sum + term*a[0][i];
        }

        printf("\nInterpolated value using Newton Divided Difference = %.2f\n",sum);
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}