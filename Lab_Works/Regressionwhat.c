#include<stdio.h>
#include<math.h>

int main()
{
    int n,i;
    float x[50],y[50];
    float sumx=0,sumy=0,sumxy=0,sumx2=0;
    float sumx3=0,sumx4=0,sumx2y=0;
    float a,b,c;
    
    printf("Enter number of observations: ");
    scanf("%d",&n);

    printf("Enter values of x:\n");
    for(i=0;i<n;i++)
        scanf("%f",&x[i]);

    printf("Enter values of y:\n");
    for(i=0;i<n;i++)
        scanf("%f",&y[i]);

    /* ---------- Linear Fit y = a + bx ---------- */

    for(i=0;i<n;i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i]*y[i];
        sumx2 += x[i]*x[i];
    }

    b = (n*sumxy - sumx*sumy)/(n*sumx2 - sumx*sumx);
    a = (sumy - b*sumx)/n;

    printf("\nLinear Fit: y = a + bx\n");
    printf("a = %.4f  b = %.4f\n",a,b);
    printf("Equation: y = %.4f + %.4fx\n",a,b);


    /* ---------- Exponential Fit y = ae^(bx) ---------- */

    float Y[50];
    float sumY=0,sumxY=0;

    for(i=0;i<n;i++)
        Y[i] = log(y[i]);

    for(i=0;i<n;i++)
    {
        sumY += Y[i];
        sumxY += x[i]*Y[i];
    }

    b = (n*sumxY - sumx*sumY)/(n*sumx2 - sumx*sumx);
    a = exp((sumY - b*sumx)/n);

    printf("\nExponential Fit: y = ae^(bx)\n");
    printf("a = %.4f  b = %.4f\n",a,b);
    printf("Equation: y = %.4fe^(%.4fx)\n",a,b);


    /* ---------- Quadratic Fit y = ax^2 + bx + c ---------- */

    for(i=0;i<n;i++)
    {
        sumx3 += x[i]*x[i]*x[i];
        sumx4 += x[i]*x[i]*x[i]*x[i];
        sumx2y += x[i]*x[i]*y[i];
    }

    float D,Da,Db,Dc;

    D = n*(sumx2*sumx4 - sumx3*sumx3)
        - sumx*(sumx*sumx4 - sumx2*sumx3)
        + sumx2*(sumx*sumx3 - sumx2*sumx2);

    Dc = sumy*(sumx2*sumx4 - sumx3*sumx3)
        - sumx*(sumxy*sumx4 - sumx2y*sumx3)
        + sumx2*(sumxy*sumx3 - sumx2*sumx2y);

    Db = n*(sumxy*sumx4 - sumx2y*sumx3)
        - sumy*(sumx*sumx4 - sumx2*sumx3)
        + sumx2*(sumx*sumx2y - sumxy*sumx2);

    Da = n*(sumx2*sumx2y - sumxy*sumx3)
        - sumx*(sumx*sumx2y - sumxy*sumx2)
        + sumy*(sumx*sumx3 - sumx2*sumx2);

    c = Dc/D;
    b = Db/D;
    a = Da/D;

    printf("\nQuadratic Fit: y = ax^2 + bx + c\n");
    printf("a = %.4f  b = %.4f  c = %.4f\n",a,b,c);
    printf("Equation: y = %.4fx^2 + %.4fx + %.4f\n",a,b,c);

    return 0;
}