#include <stdio.h>
#include <stdlib.h>
int Buscar(int num, int* v, int len)
{
	int i=0;
	int achado = -1;
	while(achado==-1 && i<len)
	{
		if(v[i]==num)
		{
			achado=i;
		}
		i++;
	}
	return achado;
}
void Trocar(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void Ordena(int* seq, int len)
{
	for(int i=0; i<len;i++)
	{
		for(int j=0; j<len;j++)
		{
			if(seq[i]<seq[j])
			{
				Trocar(&seq[i],&seq[j]);
			}
		}
	}
}


int main()
{
	int n,num;
	printf("Insira o valor de n: \n");
	scanf("%d",&n);
	int* v = (int*) malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		printf("Insira o elemendo %d: ",i);
		scanf("%d",&v[i]);
	}

	for(int i=0;i<n;i++)
	{
		printf("%d ",v[i]);
	}
	Ordena(v,n);
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",v[i]);
	}
	free(v);
	return 0;
}