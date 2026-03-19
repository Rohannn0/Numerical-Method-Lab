/*Solution of ordinary differential equation using Euler’s Method, Heun’s Method and
4th order Runge-Kutta Method*/
#include <stdio.h>

/* Define the differential equation dy/dx = f(x,y) */
float f(float x, float y)
{
    return x + y;   // Example equation
}

int main()
{
    int choice,i,n;
    float x0,y0,h,x,y,k1,k2,k3,k4;

    printf("Choose Method\n");
    printf("1. Euler Method\n");
    printf("2. Heun Method\n");
    printf("3. Runge-Kutta 4th Order\n");

    scanf("%d",&choice);

    printf("Enter initial values x0 and y0: ");
    scanf("%f%f",&x0,&y0);

    printf("Enter step size h: ");
    scanf("%f",&h);

    printf("Enter number of steps: ");
    scanf("%d",&n);

    x=x0;
    y=y0;

    if(choice==1)
    {
        printf("\nEuler Method:\n");

        for(i=1;i<=n;i++)
        {
            y = y + h * f(x,y);
            x = x + h;

            printf("Step %d  x=%.2f  y=%.4f\n",i,x,y);
        }
    }

    else if(choice==2)
    {
        printf("\nHeun Method:\n");

        for(i=1;i<=n;i++)
        {
            float k1 = f(x,y);
            float k2 = f(x+h, y+h*k1);

            y = y + (h/2)*(k1+k2);
            x = x + h;

            printf("Step %d  x=%.2f  y=%.4f\n",i,x,y);
        }
    }

    else if(choice==3)
    {
        printf("\nRunge-Kutta 4th Order Method:\n");

        for(i=1;i<=n;i++)
        {
            k1 = h * f(x,y);
            k2 = h * f(x + h/2 , y + k1/2);
            k3 = h * f(x + h/2 , y + k2/2);
            k4 = h * f(x + h , y + k3);

            y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
            x = x + h;

            printf("Step %d  x=%.2f  y=%.4f\n",i,x,y);
        }
    }

    else
    {
        printf("Invalid Choice");
    }

    return 0;
}