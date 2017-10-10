#include <stdio.h>
#include <stdlib.h>
#define linhas 3
#define colunas 3
typedef struct dados
{
	int win;
	int winner;
}dados; 
dados verificar(int** a)
{
	int i=0;
	int j=0;
	int winner=-1;
	int win=-1;
	dados retorno;
	while(i<3 && win==-1)
	{
		if(a[i][0]==a[i][1] && a[i][1]==a[i][2] && a[i][0]!=-1)
		{
			win=1;
			winner=a[i][0];
		}
		i++;
	}
	while(j<3 && win==-1)
	{
		if(a[0][j]==a[1][j] && a[1][j]==a[2][j] && a[0][j]!=-1)
		{
			win=1;
			winner=a[0][j];
		}
		i++;
	}
	if(a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][j]!=-1)
	{
		win=1;
	}
	else if(a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[0][2]==-1)
	{
		win=1;
		winner=a[0][2];
	}
	retorno.win=win;
	retorno.winner=winner;
}

int main()
{
	/*Cria a matriz A*/
	char** matriz = (char**) malloc(linhas*sizeof(char*));
	for(int i=0;i<linhas;i++)
	{
		matriz[i] = (char*) malloc(colunas*sizeof(char));
		for(int j=0; j<colunas;j++)
		{
			matriz[i][j]='.';
		}
	}
	for(int i=0;i<linhas;i++)
	{
		printf("|%c %c %c|\n",matriz[i][0],matriz[i][1],matriz[i][2] );
	}
	printf("Vez do 0");
	printf("Insira a coluna:\n");
	return 0;
}