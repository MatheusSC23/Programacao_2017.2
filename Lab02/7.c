#include <stdio.h>
#include <math.h>
double pot(double x, int k)
{
	if(k==1)
	{
		return x;
	}
	else if(k==0)
	{
		return 1;
	}
	else
	{
		return x*pot(x,k-1);
	}
}


int main(){
	double x;
	int k;
	printf("Insira a base: \n");
	scanf("%lg",&x);
	printf("Insira um expoente maior que zero: \n");
	scanf("%d",&k);
	printf("%lg elevado a %d dá %lg\n",x,k,pot(x,k));
	return 1;
}
