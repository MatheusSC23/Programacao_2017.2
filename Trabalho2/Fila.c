#include "Fila.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct fila
{
	Aluno* alunoHead;
	Aluno* alunoTail;
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
	fila->alunoHead=NULL;
	fila->alunoTail=fila->alunoHead;
	fila->elementos=0;
	return fila;
}
void destroi_f(Fila *fila)
{
	if(fila!=NULL)
	{
		free(fila->alunoHead);
		fila->alunoHead=NULL;
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
	else if(fila->alunoHead==NULL)
	{
		fila->alunoHead=aluno;
		fila->alunoTail=fila->alunoHead;
		fila->elementos++;
		return 1;
	}
	setProximo(fila->alunoTail,aluno);
	fila->alunoTail=aluno;
	fila->elementos++;
	return 1;
}
int retira_f(Fila *fila)
{
	if(fila!=NULL)
	{		
		if(fila->alunoHead!=NULL)
		{
			if(fila->alunoHead==fila->alunoTail)
			{
				fila->alunoHead=NULL;
				fila->alunoTail=NULL;
				fila->elementos--;
				return 1;
			}
			else
			{
				fila->alunoHead=getProximo(fila->alunoHead);
				fila->elementos--;
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
		int m;
		char nome[50];
		char curso[30];
		int i=1;
		Aluno *aluno=fila->alunoHead;
		while(i<=fila->elementos)
		{
			acessa_a(aluno,&m,nome,curso);
			if(m==matricula)
			{
				return aluno;
			}
			aluno=getProximo(aluno);
			i++;			
		}
		return NULL;
	}
	
	return NULL;
}
int cheia_f(Fila *fila)
{
	if(fila->tamanho==fila->elementos)
	{
		return 1;
	}
	return 0;
}