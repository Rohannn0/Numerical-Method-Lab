#include <stdio.h>

float f1(float x, float y, float z)
{
    return z;
}

float f2(float x, float y, float z)
{
    return -y;
}

int main()
{
    float x0,xn,y0,yn,h;
    float z1,z2,z;
    float y,x;
    float k1,k2,k3,k4,l1,l2,l3,l4;
    int i,n;

    printf("Enter x0, y0: ");
    scanf("%f%f",&x0,&y0);

    printf("Enter xn, yn: ");
    scanf("%f%f",&xn,&yn);

    printf("Enter step size: ");
    scanf("%f",&h);

    n=(xn-x0)/h;

    printf("Enter two initial guesses for slope: ");
    scanf("%f%f",&z1,&z2);

    float y1,y2;

    x=x0;
    y=y0;
    z=z1;

    for(i=0;i<n;i++)
    {
        k1=h*f1(x,y,z);
        l1=h*f2(x,y,z);

        k2=h*f1(x+h/2,y+k1/2,z+l1/2);
        l2=h*f2(x+h/2,y+k1/2,z+l1/2);

        k3=h*f1(x+h/2,y+k2/2,z+l2/2);
        l3=h*f2(x+h/2,y+k2/2,z+l2/2);

        k4=h*f1(x+h,y+k3,z+l3);
        l4=h*f2(x+h,y+k3,z+l3);

        y=y+(k1+2*k2+2*k3+k4)/6;
        z=z+(l1+2*l2+2*l3+l4)/6;

        x=x+h;
    }

    y1=y;

    x=x0;
    y=y0;
    z=z2;

    for(i=0;i<n;i++)
    {
        k1=h*f1(x,y,z);
        l1=h*f2(x,y,z);

        k2=h*f1(x+h/2,y+k1/2,z+l1/2);
        l2=h*f2(x+h/2,y+k1/2,z+l1/2);

        k3=h*f1(x+h/2,y+k2/2,z+l2/2);
        l3=h*f2(x+h/2,y+k2/2,z+l2/2);

        k4=h*f1(x+h,y+k3,z+l3);
        l4=h*f2(x+h,y+k3,z+l3);

        y=y+(k1+2*k2+2*k3+k4)/6;
        z=z+(l1+2*l2+2*l3+l4)/6;

        x=x+h;
    }

    y2=y;

    z = z1 + (z2-z1)*(yn-y1)/(y2-y1);

    printf("\nImproved initial slope = %f\n",z);

    x=x0;
    y=y0;

    printf("\nSolution:\n");

    for(i=0;i<=n;i++)
    {
        printf("x = %.2f   y = %.4f\n",x,y);

        k1=h*f1(x,y,z);
        l1=h*f2(x,y,z);

        k2=h*f1(x+h/2,y+k1/2,z+l1/2);
        l2=h*f2(x+h/2,y+k1/2,z+l1/2);

        k3=h*f1(x+h/2,y+k2/2,z+l2/2);
        l3=h*f2(x+h/2,y+k2/2,z+l2/2);

        k4=h*f1(x+h,y+k3,z+l3);
        l4=h*f2(x+h,y+k3,z+l3);

        y=y+(k1+2*k2+2*k3+k4)/6;
        z=z+(l1+2*l2+2*l3+l4)/6;

        x=x+h;
    }

    return 0;
}