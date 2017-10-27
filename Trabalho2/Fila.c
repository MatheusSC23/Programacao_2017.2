#include "Fila.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct fila
{
	Aluno* aluno;
	int tamanho;
	int elementos;

};
Fila *nova_f(int tamanho)
{
	if(tamanho<1)
	{
		return NULL;
	}
	/*Aloc a memória para uma fila*/
	Fila* fila = (Fila*) malloc(sizeof(Fila));
	/*Testa se há espaço pra alocação*/
	if(fila==NULL)
	{
		printf("Memoria insuficiente!\n");
		exit(1);
	}
	/*Define o tamanho da fila*/
	fila->tamanho=tamanho;
	fila->aluno=NULL;
	fila->elementos=0
	return fila;
}
void destroi_f(Fila *fila)
{
	if(fila!=NULL)
	{
		free(fila->alunos);
		fila->alunos=NULL;
		free(fila);
		fila=NULL;
	}
	
}
int adiciona_f(Fila *fila, Aluno *aluno)
{

	if(fila==NULL || aluno==NULL)
	{
		return 0;
	}
	else if(cheia_f(fila))
	{
		return 0;
	}
	else if(fila->aluno==NULL)
	{
		fila->aluno=aluno;
		fila->elementos++;
		return 1;
	}
	/*Pegar o próximo espaço vago e adicionar o aluno nele*/
	int prox=(fila->ultimo+1)%fila->tamanho;
	fila->alunos[prox]=aluno;
	fila->ultimo=prox;
	return 1;
}
int retira_f(Fila *fila)
{
	if(fila!=NULL)
	{
		
		if(fila->primeiro!=-1)
		{
			if(fila->primeiro==fila->ultimo)
			{
				fila->ultimo=-1;
				fila->primeiro=fila->ultimo;
				return 1;
			}
			else
			{
				int prox= (fila->primeiro+1)%fila->tamanho;
				fila->primeiro=prox;
				return 1;
			}
		}
		return 0;
	}
	return 0;

}
Aluno* busca_f(Fila *fila, int matricula)
{
	if(fila!=NULL && matricula>0)
	{
		int i=fila->primeiro;
		int m;
		char nome[50];
		char curso[30];
		int tamanho=0;
		while(i<=fila->ultimo && tamanho<fila->tamanho)
		{
			Aluno *aluno=fila->alunos[i];
			acessa_a(aluno,&m,nome,curso);
			if(m==matricula)
			{
				return fila->alunos[i];
			}
			i=(i+1)%fila->tamanho;
			tamanho++;
			
		}
		return NULL;
	}
	
	return NULL;
}
int cheia_f(Fila *fila)
{
	int prox = (fila->ultimo+1)%fila->tamanho;;
	if(prox== fila->primeiro)
	{
		return 1;
	}
	return 0;
}