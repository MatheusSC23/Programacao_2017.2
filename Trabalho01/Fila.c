#include "Fila.h"
struct fila
{
	Aluno* alunos;
	int tamanho;
	int primeiro,ultimo;

}
Fila *novo_f(int tamanho)
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
	Aluno* alunos = (Alunos*) malloc(tamanho*tamanho_a());
	/*Testa se há espaço pra alocação*/
	if(alunos==NULL)
	{
		printf("Memoria insuficiente!\n");
		exit(1);
	}
	alunos[0]=NULL;
	/*A sua fila recebe como alunos o ponteiro alunos*/
	fila->alunos=alunos
	return alunos;
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
	if(fila->alunos[(fila->ultimo)]==NULL && fila->alunos[(fila->primeiro)]==NULL)
	{
		fila->alunos[fila->primeiro]=aluno;
		return 1;
	}
	/*Pegar o próximo espaço vago e adicionar o aluno nele*/
	else if((fila->ultimo)+1<fila->tamanho)
	{
		fila->alunos[(fila->ultimo)+1]=aluno;
		fila->ultimo++;
		return 1;
	}
	return 0;
}