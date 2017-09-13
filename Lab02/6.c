#include <stdio.h>
#include <math.h>
double delta(double a, double b, double c){
	return b*b-(4*a*c);
}
int raizes (double a,double b,double c, double *px1, double *px2) {
	
	double d = delta(a,b,c);
	if(d == 0){
		*px1= -b/2*a;
		*px2= -b/2*a;
	}
	else if(d>0){
		*px1 = (-b+sqrt(d))/(2*a);
		*px2 = (-b-sqrt(d))/(2*a);
	}
	else{
		return 1;
	}
    return 0;
}
int main()
{
	double a,b,c,*px1,*px2;
	printf("Insira o valor de a: ");
	scanf("%lg",&a);
	printf("Insira o valor de b:  ");
	scanf("%lg",&b);
	printf("Insira o valor de c: ");
	scanf("%lg",&c);
	int flag= raizes(a,b,c,&px1,&px2);
	if(flag==1){
		printf("Não há raizes\n");
	}
	else
	{
		printf("As raizes são %lg, %lg\n", *px1,*px2);
	}
	return 0;
}