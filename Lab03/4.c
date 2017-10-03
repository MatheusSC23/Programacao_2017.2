#include <stdio.h>
#define ordem 10
double escala(double a[],double b[])
{
	int soma=0;
	for(int i=0;i<ordem;i++)
	{
		soma+=a[i]*b[i];
	}
	return soma;
}
int main()
{
	double a[ordem];
	double 	b[ordem];
	printf("Insirindo A\n");
	for(int i=0; i<ordem;i++)
	{
		printf("Insira o elemento %d  ", i+1);
		scanf("%lg",&a[i]);
	}
	printf("Insirindo B\n");
	for(int i=0; i<ordem;i++)
	{
		printf("Insira o elemento %d  ", i+1);
		scanf("%lg",&b[i]);
	}
	printf("%lg",escala(a,b));
	return 0;
}
