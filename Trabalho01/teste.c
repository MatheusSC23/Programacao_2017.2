#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
int main()
{
	int m;
	int matricula = 400501;
	char* nome= "Matheus";
	char* curso= "Ciência da Computação";
	Aluno* a = novo_a(matricula,nome,curso);
	printf("%d\n",tamanho_a());

	return 0;
}