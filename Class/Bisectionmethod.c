//Bisection Method (without allowed error concept)
#include<stdio.h>
float FindValueAt(float x){
    return x*x*x-2*x-5; //equation to be solved
}
float bisect(float x1,float x2){
    return (x1+x2)/2;
}
int main(){
    int maxiteration,i=1;
    float x1,x2,x;
    printf("Enter the maximum number of iteration to be solved:");
    scanf("%d",&maxiteration);
    do{
        printf("Enter the value of x1 and x2(intial boundary):");
        scanf("%f%f",&x1,&x2);
        if(FindValueAt(x1)*FindValueAt(x2)>0){
            printf("Root doesn't lie between the boundary\n");
            continue;
        }
        else{
            printf("Root lies between the boundary\n");
            break;
        }
    }while(1);
    while(i<=maxiteration){
        x=bisect(x1,x2);
        if(FindValueAt(x1)*FindValueAt(x)<0){
            x2=x;
        }
        else if(FindValueAt(x)*FindValueAt(x2)<0){
            x1=x;
        }
        printf("Iteration=%d    Root=%f\n",i,x);
        i++;
    }
    printf("Root=%f Total Iteration=%d",x,--i);
    return 0;
}