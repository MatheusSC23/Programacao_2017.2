#include<stdio.h>
#include<math.h>
int main(){
	double r,a;
	printf("Insira o grau em radianos: ");
	scanf("%lg",&a);
	printf("Insira o raio: ");
	scanf("%lg",&r);
	double x = r*cos(a);
	double y = r*sin(a);
	printf("(%lg,%lg)\n",x,y);
	return 1;
}