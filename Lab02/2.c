#include <stdio.h>
#include <math.h>
int primo(int n)
{
	if (n == 2) 
	{
		return 1;
	} 
	else if (n<2 || (n%2)==0) 
	{
		return 0;
	}
	else 
	{
		int lim = (int ) sqrt(n);
		for (int i=3; i<= lim; i+=2) 
		{
			if (n% i == 0) 
			{
				return 0;
			}
		}
		return 1;
	}
}


int main(){
	int x,count,j;
	printf("Insira um limite: \n");
	scanf("%d", &x);
	printf("Números menores que %d\n", x);
	for (int i=0; i<=x; i++) 
	{
		if(primo(i))
		{
			printf("%d\n", i);
		}
			
	}
	printf("Insira o número de termos: \n");
	scanf("%d", &x);
	count=0;
	j=0;
	while(count<x)
	{
		if(primo(j))
		{
			printf("%d\n", j);
			count++;
		}
		j++;		
	}
	return 1;
}