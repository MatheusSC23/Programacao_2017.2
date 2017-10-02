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
	int a[ORDEM]={2,1,3,4,10,6,7,8,9,5};
	printf("O maior será %d e o menor %d.\n",max(a),min(a) );
	return 0;
}