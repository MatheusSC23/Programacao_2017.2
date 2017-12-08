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

	} else {
		printf("[Falhou 0.0] - Teste da função atribui_v() com dados válidos!\n");			
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

	} else {
			printf("[Falhou 0.00] - Teste da função atribui_v() com dados inválidos!\n");
	}
	return pontuacao;
}

float testeAtribuiComDadosNulos() {
	int dia,mes,ano,periodo,id;
	char cidade[61];
	char pais[31];
	float pontuacao=0;
	Viagem *viagem = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	if(viagem !=NULL){
		atribui_v(viagem,2,3,2013,NULL,"EUA",20);
		atribui_v(viagem,2,3,2013,"Jerusalem", NULL,20);
		atribui_v(viagem,2,3,2013,NULL,NULL,20);
		acessa_v(viagem,&dia,&mes,&ano,cidade,pais,&periodo,&id);
		if(dia == 23 && mes == 12 && ano == 2017 && strcmp(cidade,"Fortaleza") == 0 && strcmp(pais,"Brasil") == 0 && periodo == 10){
			printf("[Passou 1.00] - Teste da função atribui_v() com dados nulos!\n");
			pontuacao = 1.0;
		} else {
			printf("[Falhou 0.00] - Teste da função atribui_v() com dados nulos!\n");
		}

	} else {
			printf("[Falhou 0.00] - Teste da função atribui_v() com dados nulos!\n");
	}

	return pontuacao;

}
float testeLiberaComDadosValidos(){
	int dia,mes,ano,periodo,id;
	char cidade[61];
	char pais[31];
	float pontuacao;
	Viagem *viagem = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	libera_v(viagem);
	if(viagem != NULL){
		acessa_v(viagem,&dia,&mes,&ano,cidade,pais,&periodo,&id);
		if(dia == 23 && mes == 12 && ano == 2017 && strcmp(cidade,"Fortaleza") == 0 && strcmp(pais,"Brasil") == 0 && periodo == 10){
			printf("[Falhou 0.00] - Teste da função libera_v() com dados válidos!\n");
		}
		else{
			printf("[Passou 0.65] - Teste da função libera_v() com dados válidos!\n");
			pontuacao =0.65;
		}
	} else {
		printf("[Passou 0.65] - Teste da função libera_v() com dados válidos!\n");
		pontuacao =0.65;
	}
	return pontuacao;

}
float testeLiberarUsuarioComDadosValidos(){
	int id1,id2,id3;
	char nome1[81],nome2[81],nome3[81];
	float pontuacao = 0;
	Usuario* Matheus = novo_u(6,"Matheus");
	Usuario* user1 = novo_u(1,"user1");
	Usuario* user2 = novo_u(2,"user2");
	Usuario* user3 = novo_u(3,"user3");
	Usuario* user4 = novo_u(4,"user4");
	Usuario* user5 = novo_u(5,"user5");

	adiciona_amigo_u(Matheus,user1);
	adiciona_amigo_u(Matheus,user2);
	adiciona_amigo_u(Matheus,user3);
	adiciona_amigo_u(Matheus,user4);
	adiciona_amigo_u(Matheus,user5);

	libera_u(user3);
	libera_u(user4);
	if(Matheus != NULL && user1 != NULL && user2 != NULL && user5 != NULL){
		Usuario** vetor = lista_amigos_u(Matheus);
		acessa_u(vetor[0],&id1,nome1);
		acessa_u(vetor[1],&id2,nome2);
		acessa_u(vetor[2],&id3,nome3);
		if(id1 == 1 && id2 == 2 && id3 == 5 && strcmp(nome1,"user1") == 0 && strcmp(nome2,"user2") == 0 && strcmp(nome3,"user5") == 0){
			printf("[Passou 0.01] - Teste da função libera_u() com dados válidos!\n");
			pontuacao = 0.01;
		}
		else{
			printf("[Falhou 0.00] - Teste da função libera_u() com dados válidos!\n");
		}
	}
	else{
			printf("[Falhou 0.00] - Teste da função libera_u() com dados válidos!\n");
	}
	libera_u(Matheus);
	libera_u(user1);
	libera_u(user2);
	libera_u(user5);

	return pontuacao;

}
float testeRemoverAmigoComDadosValidos(){
	float pontuacao=0.0;
	int id;
	char nome[81];

	Usuario* Matheus = novo_u(1,"Matheus");
	Usuario* A = novo_u(2,"A");
	adiciona_amigo_u(Matheus,A);
	Usuario** vetor = lista_amigos_u(Matheus);

	if(Matheus != NULL && A != NULL){
		acessa_u(vetor[0],&id,nome);
		if(id == 2 && strcmp(nome,"A") == 0){
			remove_amigo_u(Matheus,2);
			vetor = lista_amigos_u(Matheus);
			if(vetor == NULL){
				printf("[Passou 0.01] - Teste da função remove_amigo_u() com dados válidos!\n");
				pontuacao = 0.01;
			}
			else{
				printf("[Falhou 0.00*] - Teste da função remove_amigo_u() com dados válidos!\n");
			}
		}		
		else{
				printf("[Falhou 0.00**] - Teste da função remove_amigo_u() com dados válidos!\n");
		}		
	}

}

float testeNovoUsuarioComDadosValidos(){
	float pontuacao = 0.0;
	int id;
	char nome[81];
	Usuario* user = novo_u(0,"Matheus");
	if(user != NULL){
		acessa_u(user,&id,nome);
		if(strcmp(nome,"Matheus") == 0 && id == 0){
			printf("[Passou 0.01] - Teste da função novo_u() com dados válidos!\n");
			pontuacao = 0.01;
		}
		else{
			printf("[Falhou 0.00] - Teste da função novo_u() com dados válidos!\n");
		}
	}
	else{
		printf("[Falhou 0.00] - Teste da função novo_u() com dados válidos!\n");
	}
	libera_u(user);
	return pontuacao;

}
float testeAdicionaAmigosComDadosValidos(){
	float pontuacao=0.0;
	int id;
	char nome[81];
	
	Usuario* Matheus = novo_u(1,"Matheus");
	Usuario* A = novo_u(2,"A");
	Usuario* B = novo_u(3,"B");
	adiciona_amigo_u(Matheus,A);
	adiciona_amigo_u(Matheus,B);
	Usuario** vetor = lista_amigos_u(Matheus);
	if(Matheus != NULL && A != NULL && B != NULL){
		acessa_u(vetor[0],&id,nome);
		if(id == 2 && strcmp(nome,"A") == 0){
			acessa_u(vetor[1],&id,nome);
			if(id == 3 && strcmp(nome,"B") == 0){
				printf("[Passou 0.01] - Teste da função adiciona_amigo_u() com dados válidos!\n");
				pontuacao=0.01;
			}
			else{
				printf("[Falhou 0.00] - Teste da função adiciona_amigo_u() com dados válidos!\n");

			}
		}
		else{
				printf("[Falhou 0.00] - Teste da função adiciona_amigo_u() com dados válidos!\n");

		}
		
	}
	else{
				printf("[Falhou 0.00] - Teste da função adiciona_amigo_u() com dados válidos!\n");

	}
	libera_u(Matheus);
	libera_u(A);
	libera_u(B);
	return pontuacao;

}
float testeAdicionaAmigosComDadosInvalidos(){
	float pontuacao=0.0;
	int id;
	char nome[81];
	
	Usuario* Matheus = novo_u(1,"Matheus");
	Usuario* A = novo_u(-1,"A");
	Usuario* B = novo_u(1,"B");
	adiciona_amigo_u(Matheus,A);
	adiciona_amigo_u(Matheus,B);
	Usuario** vetor = lista_amigos_u(Matheus);
	if(Matheus != NULL && A == NULL && B == NULL){
		if(vetor == NULL){
			printf("[Passou 0.01] - Teste da função adiciona_amigo_u() com dados inválidos!\n");
			pontuacao=0.01;
		}
		else{
			printf("[Falhou 0.00] - Teste da função adiciona_amigo_u() com dados inválidos!\n");

		}
	}
	else{
		printf("[Falhou 0.00] - Teste da função adiciona_amigo_u() com dados inválidos!\n");

	}
	libera_u(Matheus);
	return pontuacao;

}

float testeAdicionaAmigosComDadosNulos(){
	float pontuacao=0.0;
	int id;
	char nome[81];
	
	Usuario* Matheus = novo_u(1,"Matheus");
	adiciona_amigo_u(Matheus,NULL);
	Usuario** vetor = lista_amigos_u(Matheus);
	if(Matheus != NULL){
		if(vetor == NULL){
			printf("[Passou 0.01] - Teste da função adiciona_amigo_u() com dados nulos!\n");
			pontuacao=0.01;
		}
		else{
			printf("[Falhou 0.00] - Teste da função adiciona_amigo_u() com dados nulos!\n");

		}
	}
	else{
		printf("[Falhou 0.00] - Teste da função adiciona_amigo_u() com dados nulos!\n");

	}

	libera_u(Matheus);
	return pontuacao;

}

float testeNovoUsuarioComDadosInvalidos(){
	float pontuacao = 0.0;
	int id;
	char nome[81]="N";
	Usuario* user1 = novo_u(0,"Matheus");
	Usuario* user2 = novo_u(-1,"Maria");
	Usuario* user3 = novo_u(0,"Marta");
	Usuario* user4 = novo_u(0,nome);
	for (int i = 0; i < 81; i++) {
		strcat(nome, "N");
	}
	if(user1 != NULL && user2 == NULL && user3 == NULL && user4 == NULL){
		acessa_u(user1,&id,nome);
		if(strcmp(nome,"Matheus") == 0 && id == 0){
			printf("[Passou 0.01] - Teste da função novo_u() com dados inválidos!\n");
			pontuacao = 0.01;
		}
		else{
			printf("[Falhou 0.00] - Teste da função novo_u() com dados inválidos!\n");
		}
	}
	else{
		printf("[Falhou 0.00] - Teste da função novo_u() com dados inválidos!\n");
	}

	libera_u(user1);
	return pontuacao;

}

float testeListarAmigosComDadosValidos() {
	float pontuacao=0.0;
	int id;
	char nome[81];
	
	Usuario* Matheus = novo_u(1,"Matheus");
	Usuario* A = novo_u(2,"A");
	Usuario* B = novo_u(3,"B");
	Usuario* C = novo_u(4,"C");
	Usuario* D = novo_u(5,"D");
	Usuario* E = novo_u(6,"E");
	adiciona_amigo_u(Matheus,A);
	adiciona_amigo_u(Matheus,B);
	adiciona_amigo_u(Matheus,C);
	adiciona_amigo_u(Matheus,D);
	adiciona_amigo_u(Matheus,E);
	Usuario** vetor = lista_amigos_u(Matheus);
	/*
		if(Matheus!=NULL){
			acessa_u(vetor[0],&id,nome);
			printf("%s %d \n", nome,id);
			acessa_u(vetor[1],&id,nome);
			printf("%s %d \n", nome,id);
			acessa_u(vetor[2],&id,nome);
			printf("%s %d \n", nome,id);
			acessa_u(vetor[3],&id,nome);
			printf("%s %d \n", nome,id);
			acessa_u(vetor[4],&id,nome);
			printf("%s %d \n", nome,id);
		}
	*/
	/*if(Matheus!=NULL){
		acessa_u(vetor[0],&id,nome);
		if(strcmp(nome,"A")==0 && id==2){
			printf("[Passou 0.65] - Teste da função lista_amigos_u() com dados válidos!\n");
			pontuacao=0.65;
		}
		else {
			printf("[Falhou 0.00] - Teste da função lista_amigos_u() com dados válidos!\n");
		}
	}
	else {
			printf("[Falhou 0.00] - Teste da função lista_amigos_u() com dados válidos!\n");
	}*/
	libera_u(Matheus);
	libera_u(A);
	libera_u(B);
	libera_u(C);
	libera_u(D);
	libera_u(E);
	return pontuacao;
}
float testeAtribuiUsuarioComDadosValidos(){

	float pontuacao;
	int id;
	char nome[81];
	Usuario* Matheus = novo_u(0,"Matheus");
	atribui_u(Matheus,10,"Matheus Correia");
	if(Matheus != NULL){
		acessa_u(Matheus,&id,nome);
		printf("nome: %s id: %d\n",nome, id );
		if(id == 1 && strcmp(nome,"Matheus Correia") == 0){
			printf("[Passou 0.1] - Teste da função atribui_u() com dados válidos!\n");
			pontuacao=0.1;
		}
		else{
			printf("[Falhou 0.00] - Teste da função atribui_u() com dados válidos!\n");
		}

	}
	else{
			printf("[Falhou 0.00*] - Teste da função atribui_u() com dados válidos!\n");
	}
	return pontuacao;
}
int main(){
/*	testeNovoComDadosValidos();
	testeNovoComDadosInvalidos();
	testeNovoComDadosNulos();
	testeAcessa();
	testeAtribuiComDadosValidos();
	testeAtribuiComDadosValidos();
	testeAtribuiComDadosInvalidos();
	testeAtribuiComDadosNulos();
	testeLiberaComDadosValidos();
	printf("\n\nFunções do usuário\n\n");
	testeNovoUsuarioComDadosValidos();
	testeNovoUsuarioComDadosInvalidos();
	testeAdicionaAmigosComDadosValidos();
	testeAdicionaAmigosComDadosInvalidos();
	testeAdicionaAmigosComDadosNulos();
	testeLiberarUsuarioComDadosValidos();
	
	testeRemoverAmigoComDadosValidos();

	testeAtribuiUsuarioComDadosValidos();*/
	testeListarAmigosComDadosValidos();
	return 0;
}
