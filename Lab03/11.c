#include <stdio.h>
#include <stdlib.h>

int produto(int** A;int** v, int linhas, int colunas)
{
	int repeticoes;
	repeticoes=0;
	for(int i=0; i<linhas;i++)
	{
		for(int j=0; j<colunas; j++)
		{
			if(num==matriz[i][j])
			{
				repeticoes+=1;
			}
		}
	}
	return repeticoes;
}


int main()
{
	int linhas,colunas,num;
	printf("Insira o número de colunas: \n");
	scanf("%d",&colunas);
	printf("Insira o número de linhas: \n");
	scanf("%d",&linhas);

	int** R = (int**) malloc(linhas*sizeof(int*));
	
	int** matriz = (int**) malloc(linhas*sizeof(int*));
	for(int i=0;i<linhas;i++)
	{
		matriz[i] = (int*) malloc(colunas*sizeof(int));
		for(int j=0; j<colunas;j++)
		{
			printf("Insira o elemento da linha %d coluna %d de A:",i,j);
			scanf("%d",&matriz[i][j]);
		}
	}

	int** v = (int**) malloc(linhas*sizeof(int*));
	for(int i=0;i<linhas;i++)
	{
		for(int j=0; j<1;j++)
		{
			printf("Insira o elemento da linha %d coluna %d de v:",i,j);
			scanf("%d",&v[i][j]);
		}
	}
	
	for(int i=0;i<linhas;i++)
	{
		for(int j=0; j<colunas;j++)
		{
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}