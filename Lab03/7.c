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
	printf("Insira o valor a ser procurado: \n");
	scanf("%d",&num);
	int pos = Buscar(num,v,n);
	if(pos!=-1)
	{
		printf("O número se encontra na posição %d\n", pos);
	}
	else
	{
		printf("O número não está na sequência.\n");
	}
	free(v);
	return 0;
}