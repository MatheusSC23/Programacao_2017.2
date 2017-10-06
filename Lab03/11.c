#include <stdio.h>
#include <stdlib.h>

int main()
{
	int linhas,colunas,num;
	printf("Insira o número de linhas: \n");
	scanf("%d",&linhas);
	printf("Insira o número de colunas: \n");
	scanf("%d",&colunas);
	/*Cria a matriz A*/
	printf("Insira A:\n");	
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
	printf("Insira v:\n");	
	/*Cria a matriz v*/
	int** v = (int**) malloc(colunas*sizeof(int*));
	for(int i=0;i<colunas;i++)
	{
		v[i]= (int*) malloc(sizeof(int));
		for(int j=0; j<1;j++)
		{
			printf("Insira o elemento da linha %d coluna %d de v:",i,j);
			scanf("%d",&v[i][j]);
		}
	}
	/*Cria e calcula a matriz R*/
	for(int i=0; i<linhas;i++)
	{
		int soma=0;
		for(int j=0; j<colunas; j++)
		{
			soma+=matriz[i][j]*v[j][0];

		}
		printf("%d\n",soma );
	}
	free(matriz);
	free(v);
	
	return 0;
}