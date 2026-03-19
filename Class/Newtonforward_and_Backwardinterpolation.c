/* Newton's Forward and Backward Interpolation */
#include<stdio.h>
#include<math.h>

int main()
{
    float x,u,y;
    int i,j,n,fact,choice;

    printf("Enter number of terms: ");
    scanf("%d",&n);

    float a[n][n+1];

    printf("Enter values of X:\n");
    for(i=0;i<n;i++)
        scanf("%f",&a[i][0]);

    printf("Enter values of Y:\n");
    for(i=0;i<n;i++)
        scanf("%f",&a[i][1]);

    printf("Enter value of x for which you want y: ");
    scanf("%f",&x);

    /* Construct Difference Table */
    for(j=2;j<n+1;j++)
    {
        for(i=0;i<n-j+1;i++)
        {
            a[i][j] = a[i+1][j-1] - a[i][j-1];
        }
    }

    printf("\nDifference Table:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i+1;j++)
            printf("%8.2f",a[i][j]);
        printf("\n");
    }

    printf("\nChoose Method:\n");
    printf("1. Newton Forward Interpolation\n");
    printf("2. Newton Backward Interpolation\n");
    scanf("%d",&choice);

    if(choice==1)
    {
        /* Forward Interpolation */
        u = (x - a[0][0])/(a[1][0] - a[0][0]);
        y = a[0][1];
        float u1 = u;
        fact = 1;

        for(i=2;i<=n;i++)
        {
            y = y + (u1 * a[0][i]) / fact;
            fact = fact * i;
            u1 = u1 * (u - (i-1));
        }

        printf("\nValue using Newton Forward = %.2f\n",y);
    }
    else if(choice==2)
    {
        /* Backward Interpolation */
        u = (x - a[n-1][0])/(a[1][0] - a[0][0]);
        y = a[n-1][1];
        float u1 = u;
        fact = 1;

        for(i=2;i<=n;i++)
        {
            y = y + (u1 * a[n-i][i]) / fact;
            fact = fact * i;
            u1 = u1 * (u + (i-1));
        }

        printf("\nValue using Newton Backward = %.2f\n",y);
    }
    else
    {
        printf("Invalid choice");
    }

    return 0;
}