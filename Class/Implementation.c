/*Implementation of Trapezoidal Rule, Simpson’s 1/3 Rule, Simpson’s 3/8 Rule, Line and Double Integration.*/
#include<stdio.h>
#include<math.h>

/* Function for integration */
float f(float x)
{
    return x*x;   // Example function f(x) = x^2
}

/* Function for double integration */
float g(float x,float y)
{
    return x+y;   // Example function
}

int main()
{
    int choice,n,i,j;
    float a,b,h,sum=0,x;
    float c,d,k,l,hx,hy;

    printf("Choose Method\n");
    printf("1. Trapezoidal Rule\n");
    printf("2. Simpson 1/3 Rule\n");
    printf("3. Simpson 3/8 Rule\n");
    printf("4. Line Integration\n");
    printf("5. Double Integration\n");

    scanf("%d",&choice);

    if(choice==1)
    {
        printf("Enter lower limit and upper limit: ");
        scanf("%f%f",&a,&b);

        printf("Enter number of intervals: ");
        scanf("%d",&n);

        h=(b-a)/n;

        sum=f(a)+f(b);

        for(i=1;i<n;i++)
        {
            x=a+i*h;
            sum=sum+2*f(x);
        }

        sum=(h/2)*sum;

        printf("Integral using Trapezoidal Rule = %f",sum);
    }

    else if(choice==2)
    {
        printf("Enter lower limit and upper limit: ");
        scanf("%f%f",&a,&b);

        printf("Enter even number of intervals: ");
        scanf("%d",&n);

        h=(b-a)/n;

        sum=f(a)+f(b);

        for(i=1;i<n;i++)
        {
            x=a+i*h;

            if(i%2==0)
                sum=sum+2*f(x);
            else
                sum=sum+4*f(x);
        }

        sum=(h/3)*sum;

        printf("Integral using Simpson 1/3 Rule = %f",sum);
    }

    else if(choice==3)
    {
        printf("Enter lower limit and upper limit: ");
        scanf("%f%f",&a,&b);

        printf("Enter number of intervals (multiple of 3): ");
        scanf("%d",&n);

        h=(b-a)/n;

        sum=f(a)+f(b);

        for(i=1;i<n;i++)
        {
            x=a+i*h;

            if(i%3==0)
                sum=sum+2*f(x);
            else
                sum=sum+3*f(x);
        }

        sum=(3*h/8)*sum;

        printf("Integral using Simpson 3/8 Rule = %f",sum);
    }

    else if(choice==4)
    {
        printf("Enter limits a and b: ");
        scanf("%f%f",&a,&b);

        printf("Enter number of intervals: ");
        scanf("%d",&n);

        h=(b-a)/n;
        sum=0;

        for(i=0;i<n;i++)
        {
            x=a+i*h;
            sum=sum+f(x)*h;
        }

        printf("Line Integration = %f",sum);
    }

    else if(choice==5)
    {
        printf("Enter limits for x (a,b): ");
        scanf("%f%f",&a,&b);

        printf("Enter limits for y (c,d): ");
        scanf("%f%f",&c,&d);

        printf("Enter number of intervals in x and y: ");
        scanf("%d%d",&n,&j);

        hx=(b-a)/n;
        hy=(d-c)/j;

        sum=0;

        for(i=0;i<n;i++)
        {
            for(int k=0;k<j;k++)
            {
                sum=sum+g(a+i*hx,c+k*hy)*hx*hy;
            }
        }

        printf("Double Integration = %f",sum);
    }

    else
    {
        printf("Invalid Choice");
    }

    return 0;
}