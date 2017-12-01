#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Usuario.h"

float nota;
float testeNovoComDadosValidos(){
	char cidade[61], pais[31];
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
<<<<<<< HEAD
float testeNovoComDadosInvalidos(){
	char cidade[61] = "C";
	char pais[31] = "P";
	int dia,mes,ano,periodo,id;
	float pontuacao = 0;

	for (int i = 0; i < 61; i++) {
		strcat(cidade, "C");
	}

	for (int i = 0; i < 31; i++) {
		strcat(pais, "P");
	}

	Viagem* viagem = nova_v(32,13,1996,cidade,pais,-1);
	if(viagem == NULL){
		printf("[Passou 1.00] - Teste da função nova_v() com dados inválidos!\n");
		pontuacao = 1.00;
	}
	else{
		printf("[Falhou 0.00] - Teste da função nova_v() com dados inválidos!\n");
	}
	return pontuacao;

}

float testeNovoComDadosNulos(){
	float pontuacao=0;

	Viagem* viagem = nova_v(-1,-1,-2,NULL,NULL,-1);
	if(viagem == NULL){
		printf("[Passou 0.67] - Teste da função nova_v() com dados nulos!\n");
		pontuacao = 0.67;
	}
	else{
		printf("[Falhou 0.00] - Teste da função nova_v() com dados nulos!\n");
	}
	return pontuacao;
}

float testeAcessa(){
	int dia,mes,ano,periodo,id;
	char cidade[61], pais[31];
	float pontuacao=0;

	Viagem* viagem = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	if(viagem != NULL){
		acessa_v(viagem,&dia,&mes,&ano,cidade,pais,&periodo,&id);
		if(dia == 23 && mes == 12 && ano == 2017 && strcmp(cidade,"Fortaleza") == 0 && strcmp(pais,"Brasil")==0 && periodo == periodo ){
			printf("[Passou 1.50] - Teste da função acessa_v() com dados válidos!\n");
			pontuacao = 1.5;
		} else{
			printf("[Falhou 0.00] - Teste da função acessa_v()com dados válidos!\n");
		}
	}
}

float testeAtribuiComDadosValidos(){
	int dia,mes,ano,periodo,id;
	char cidade[61], pais[31];
	float pontuacao=0;

	Viagem* viagem = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	if(viagem !=NULL){
		atribui_v(viagem,24,12,2018,"Nova York","EUA",15);
		acessa_v(viagem,&dia,&mes,&ano,cidade,pais,&periodo,&id);
		if(dia == 24 && mes == 12 && ano == 2018 && strcmp(cidade,"Nova York")==0 && strcmp(pais,"EUA")==0 && periodo==15){
			printf("[Passou 1.50] - Teste da função atribui_v() com dados válidos!\n");
			pontuacao = 1.5;
		} else {
			printf("[Falhou 0.0] - Teste da função atribui_v() com dados válidos!\n");			
		}

	}
	return pontuacao;

}

float testeAtribuiComDadosInvalidos() {
	int dia,mes,ano,periodo,id;
	char cidade[62]="C";
	char pais[32]="P";
	float pontuacao=0;

	for (int i = 0; i < 62; i++) {
		strcat(cidade, "N");
	}

	for (int i = 0; i < 32; i++) {
		strcat(pais, "C");
	}

	Viagem* viagem = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	if(viagem != NULL){
		atribui_v(viagem,1,2,2012,cidade,pais,20);
		acessa_v(viagem,&dia,&mes,&ano,cidade,pais,&periodo,&id);
		if(dia == 23 && mes == 12 && ano == 2017 && strcmp(cidade,"Fortaleza") == 0 && strcmp(pais,"Brasil") == 0 && periodo == 10){
			printf("[Passou 1.00] - Teste da função atribui_v() com dados inválidos!\n");
			pontuacao = 1;
		} else{
			printf("[Falhou 0.00] - Teste da função atribui_v() com dados inválidos!\n");
		}

	}
}
int main(){
	testeNovoComDadosValidos();
	testeNovoComDadosInvalidos();
	testeNovoComDadosNulos();
	testeAcessa();
	testeAtribuiComDadosValidos();
	testeAtribuiComDadosValidos();
	testeAtribuiComDadosInvalidos();
	return 0;
}
=======
>>>>>>> d41db876d13299ce7a043a9bd6cd34b98bd17f02
