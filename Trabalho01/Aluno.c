#include <stdlib.h>
#include <stdio.h>
#include "Aluno.h"
#include <string.h>

struct aluno
{
	int matricula;
	char nome[50];
	char curso[30];
};  

Aluno* novo_a(int matricula, char *nome, char *curso)
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

void libera_a(Aluno *aluno)
{
	free(aluno);
	aluno=NULL;
}
void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso)
{
	*matricula=aluno->matricula;
	strcpy(nome,aluno->nome);
	strcpy(curso,aluno->curso);
}
void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso)
{
	aluno->matricula=matricula;
	strcpy(aluno->nome,nome);
	strcpy(aluno->curso,curso);
}
int tamanho_a()
{
	return sizeof(Aluno);
}