/*Derivatives from divided difference table*/
#include<stdio.h>

int main()
{
    int n,i,j;
    float x[10],a[10][10];

    printf("Enter number of data points: ");
    scanf("%d",&n);

    printf("Enter values of x:\n");
    for(i=0;i<n;i++)
        scanf("%f",&x[i]);

    printf("Enter values of y:\n");
    for(i=0;i<n;i++)
        scanf("%f",&a[i][0]);

    /* Divided Difference Table */
    for(j=1;j<n;j++)
    {
        for(i=0;i<n-j;i++)
        {
            a[i][j]=(a[i+1][j-1]-a[i][j-1])/(x[i+j]-x[i]);
        }
    }

    printf("\nDivided Difference Table:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
            printf("%10.4f",a[i][j]);
        printf("\n");
    }

    /* First derivative at x0 */
    float derivative;

    derivative = a[0][1] + (2*x[0]-x[1]-x[2])*a[0][2];

    printf("\nFirst derivative at x = %.2f is %.4f\n",x[0],derivative);

    return 0;
}