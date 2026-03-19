/* Secant Method and Newton-Raphson Method */
#include <stdio.h>

/* Example function: f(x) = x^3 - x - 2 */
float f(float x)
{
    return x*x*x - x - 2;
}

/* Derivative of f(x) for Newton-Raphson */
float df(float x)
{
    return 3*x*x - 1;
}

int main()
{
    int choice, i, n;
    float x0, x1, x_new, tol;

    printf("Choose Method:\n");
    printf("1. Newton-Raphson Method\n");
    printf("2. Secant Method\n");
    scanf("%d", &choice);

    printf("Enter tolerance: ");
    scanf("%f", &tol);

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    if(choice == 1)
    {
        /* Newton-Raphson Method */
        printf("Enter initial guess x0: ");
        scanf("%f", &x0);

        for(i=1;i<=n;i++)
        {
            x_new = x0 - f(x0)/df(x0);
            printf("Iteration %d: Root = %f\n", i, x_new);

            float diff = x_new - x0;
            if(diff < 0) diff = -diff;

            if(diff < tol)
                break;

            x0 = x_new;
        }

        printf("\nApproximate root (Newton-Raphson) = %f\n", x_new);
    }

    else if(choice == 2)
    {
        /* Secant Method */
        printf("Enter first guess x0: ");
        scanf("%f", &x0);
        printf("Enter second guess x1: ");
        scanf("%f", &x1);

        for(i=1;i<=n;i++)
        {
            x_new = x1 - f(x1)*(x1-x0)/(f(x1)-f(x0));
            printf("Iteration %d: Root = %f\n", i, x_new);

            float diff = x_new - x1;
            if(diff < 0) diff = -diff;

            if(diff < tol)
                break;

            x0 = x1;
            x1 = x_new;
        }

        printf("\nApproximate root (Secant Method) = %f\n", x_new);
    }

    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}