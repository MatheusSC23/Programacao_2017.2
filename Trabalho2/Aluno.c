#include <stdlib.h>
#include <stdio.h>
#include "Aluno.h"
#include <string.h>

struct aluno
{
	int matricula;
	char nome[50];
	char curso[30];
	Aluno* prox;
};  

Aluno* novo_a(int matricula, char *nome, char *curso)
{
	if(matricula>0 && nome!=NULL && curso!=NULL)
	{
		if(strlen(nome)<=50 && strlen(curso)<=30)
		{
			Aluno* a = (Aluno*) malloc(sizeof(Aluno));
			if(a==NULL)
			{
				printf("Memoria insuficiente!\n");
				exit(1);
			}
			a->matricula=matricula;
			strcpy(a->nome,nome);
			strcpy(a->curso,curso);
			return a;
		}
	}
	return NULL;
	
}

void libera_a(Aluno *aluno)
{
	if(aluno!=NULL)
	{	
		Aluno alunovazio;
		*aluno=alunovazio;
		free(aluno);
		aluno=NULL;
	}
}
void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso)
{
	if(aluno!=NULL)
	{
		*matricula=aluno->matricula;
		strcpy(nome,aluno->nome);
		strcpy(curso,aluno->curso);
	}
	
}
void setProximo(Aluno* aluno)
{
	aluno->prox=aluno;
}
void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso)
{
	if(aluno!=NULL && matricula>0 && nome!=NULL && curso!=NULL)
	{
		if(strlen(nome)<=50 && strlen(curso)<=30)
		{
			aluno->matricula=matricula;
			strcpy(aluno->nome,nome);
			strcpy(aluno->curso,curso);
		}
	}
	
}
int tamanho_a()
{
	return sizeof(Aluno);
}