#include "Fila.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct fila
{
	Aluno** alunos;
	int tamanho;
	int primeiro,ultimo;

};
Fila *nova_f(int tamanho)
{
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
	/*Aloca um espaço na memória para um ponteiro alunos*/
	Aluno** alunos = (Aluno**) malloc(tamanho*tamanho_a());
	/*Testa se há espaço pra alocação*/
	if(alunos==NULL)
	{
		printf("Memoria insuficiente!\n");
		exit(1);
	}
	/*A sua fila recebe como alunos o ponteiro alunos*/
	fila->alunos=alunos;
	fila->alunos[0]=NULL;
	
	
	fila->primeiro=-1;
	fila->ultimo=-1;
	return fila;
}
void destroi_f(Fila *fila)
{
	free(fila->alunos);
	fila->alunos=NULL;
	free(fila);
	fila=NULL;
}
int adiciona_f(Fila *fila, Aluno *aluno)
{
	if(fila->primeiro==-1)
	{
		fila->primeiro=0;
		fila->ultimo=0;
		fila->alunos[fila->primeiro]=aluno;
		return 1;
	}
	/*Pegar o próximo espaço vago e adicionar o aluno nele*/
	else if(!cheia_f(fila))
	{
		int prox=(fila->ultimo+1)%fila->tamanho;
		fila->alunos[prox]=aluno;
		fila->ultimo=prox;
		return 1;
	}
	return 0;
}
int retira_f(Fila *fila)
{
	int prox= (fila->primeiro+1)%fila->tamanho;
	if(fila->primeiro!=-1)
	{
		if(fila->primeiro==fila->ultimo)
		{
			libera_a(fila->alunos[fila->primeiro]);
			fila->alunos[fila->primeiro]==NULL;
			fila->ultimo=-1;
			fila->primeiro=fila->ultimo;
			return 1;
		}
		else
		{
			libera_a(fila->alunos[fila->primeiro]);
			fila->alunos[fila->primeiro]==NULL;
			fila->primeiro=prox;
			return 1;
		}
	}
}
Aluno* busca_f(Fila *fila, int matricula)
{
	int i=0;
	int m;
	char* nome;
	char* curso;
	int True=1;
	Aluno* aluno=NULL;
	while(i<fila->tamanho && True)
	{
		;
		acessa_a(fila->alunos[i],&m,nome,curso);
		if(m==matricula)
		{
			True=0;
			aluno=fila->alunos[i];
		}
		i++;
	}
	return aluno;
}
int cheia_f(Fila *fila)
{
	if(fila->ultimo+1== fila->primeiro)
	{
		return 1;
	}
	return 0;
}