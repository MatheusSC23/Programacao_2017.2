#include <stdio.h>
#include <stdlib.h>

int repeticoes(int num,int** matriz, int linhas, int colunas)
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
void escalar(int num,int** matriz, int linhas, int colunas)
{
	for(int i=0; i<linhas;i++)
	{
		for(int j=0; j<colunas; j++)
		{
			matriz[i][j]*=num;
		}
	}
}

int main()
{
	int linhas,colunas,num;
	printf("Insira o número de colunas: \n");
	scanf("%d",&colunas);
	printf("Insira o número de linhas: \n");
	scanf("%d",&linhas);
	int **matriz = (int**) malloc(linhas*sizeof(int*));
	for(int i=0;i<linhas;i++)
	{
		matriz[i] = (int*) malloc(colunas*sizeof(int));
		for(int j=0; j<colunas;j++)
		{
			printf("Insira o elemento da linha %d coluna %d:",i,j);
			scanf("%d",&matriz[i][j]);
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
	printf("Insira o escalar: \n");
	scanf("%d",&num);
	escalar(num,matriz,linhas,colunas); 
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