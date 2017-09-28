#include <stdio.h>
#define ORDEM 10
int max(int a[])
{
	int maior = a[0];
	for(int i=0; i<10; i++)
	{
		if(maior<a[i])
		{
			maior=a[i];
		}
	}
	return maior;
}
int min(int a[])
{
	int menor = a[0];
	for(int i=0; i<ORDEM; i++)
	{
		if(menor>a[i])
		{
			menor=a[i];
		}
	}
	return menor;
}
int main()
{
	int a[ORDEM]={1,2,3,4,5,6,7,8,9,10};
	
	return 0;
}