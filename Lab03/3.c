#include <stdlib.h>
#include <stdio.h>
float melhor(int a[], int len)
{
	float melhor=a[0];
	for(int i=0;i<len;i++)
	{
		if(melhor>a[i])
		{
			melhor=a[i];
		}
	}
	return melhor;
}

int volta(int a[], int len)
{
	int volta=1;
	float melhor=a[0];
	for(int i=0;i<len;i++)
	{
		if(melhor>a[i])
		{
			melhor=a[i];
			volta=i+1;
			
		}
	}
	return volta;
}

float pior(int a[], int len)
{
	float pior=a[0];
	for(int i=0;i<len;i++)
	{
		if(pior<a[i])
		{
			pior=a[i];
		}
	}
	return pior;
}
int piorVolta(int a[],int len)
{
	int volta=1;
	float pior=a[0];
	for(int i=0;i<len;i++)
	{
		if(pior<a[i])
		{
			pior=a[i];
			volta=i+1;
			
		}
	}
	return volta;
}
double media(int a[],int len)
{
	double media=0;
	for(int i=0;i<len;i++)
	{
		media+=a[i];
	}
	media/=len;
	return media;
}
int main(){
	int n;
	printf("Insira o número de elementos:");
	scanf("%d",&n);
	int* a =(int*) malloc(n*sizeof(int));;
	for(int i=0;i<n;i++)
	{
		printf("Insira o elemento %d:",i+1);
		scanf("%d",&a[i]);
	}
   
    
    printf("Melhor tempo %0.2f\nVolta do melhor tempo %d\nPior tempo %0.2f\nVolta do pior tempo %d\nMédia dos tempos %lg",melhor(a,n),volta(a,n),pior(a,n),piorVolta(a,n), media(a,n));
	free(a);
    return 0;
  }
  
