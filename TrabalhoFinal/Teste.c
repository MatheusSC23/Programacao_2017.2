#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Usuario.h"

float nota;
float testeNovoComDadosValidos(){
	char nome[61], pais[31];
	int dia,mes,ano,periodo,id;
	float pontuacao = 0;

	Viagem* viagem = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	if(viagem != NULL){
		printf("[Passou 1.50] - Teste da função nova_v() com dados válidos!\n");
		pontuacao = 1.5;
	}
	else{
		printf("[Falhou 0.00] - Teste da função nova_v() com dados válidos!\n");
	}
	return pontuacao;
}
