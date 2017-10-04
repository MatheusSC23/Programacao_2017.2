#include <stdio.h>
#include <stdlib.h>



int main()
{
	int linhas,colunas;
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
			printf("%d",matriz[i][j]);
		}
	}
	return 0;
}