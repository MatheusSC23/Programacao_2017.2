#include <stdlib.h>
#include <stdio.h>
#include "Aluno.h"

struct aluno
{
	int matricula;
	char *nome;
	char *curso;
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
	a->nome=nome;
	a->curso=curso;
	return a;
}

void libera_a(Aluno *aluno)
{
	free(aluno);
}
void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso)
{
	*matricula=aluno->matricula;
	nome=aluno->nome;
	curso=aluno->curso;
}
void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso)
{
	aluno->matricula=matricula;
	aluno->nome=nome;
	aluno->curso,curso;
}
int tamanho_a(Aluno *aluno)
{
	return sizeof(*aluno);
}