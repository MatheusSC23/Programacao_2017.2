#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
int main()
{
	int matricula = 400501;
	int m;
	char* c;
	char* n;
	char* nome= "Matheus";
	char* curso= "Ciência da Computação";
	Aluno* a = novo_a(matricula,nome,curso);
	a=acessa_a(a,&m,n,c);
	int i;
	printf("%s\n",n);
	
	return 0;
}