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
	if(Matheus != NULL && user1 != NULL && user2 != NULL && user5 != NULL && user4 == NULL && user3 == NULL){
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
	libera_u(Matheus);
	libera_u(A);
	return pontuacao;

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

	if(Matheus!=NULL){
		acessa_u(vetor[0],&id,nome);
		if(strcmp(nome,"A")==0 && id==2){
			printf("[Passou 0.65] - Teste da função lista_amigos_u() com dados válidos!\n");
			pontuacao=0.65;
		}
		else {
			printf("[Falhou 0.00*] - Teste da função lista_amigos_u() com dados válidos!\n");
		}
	}
	else {
			printf("[Falhou 0.00**] - Teste da função lista_amigos_u() com dados válidos!\n");
	}
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
	atribui_u(Matheus,1,"Matheus Correia");
	if(Matheus != NULL){
		acessa_u(Matheus,&id,nome);
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
	libera_u(Matheus);
	return pontuacao;
}

float testeAtribuiUsuarioComDadosInvalidos(){

	float pontuacao;
	int id;
	char nome[81];
	char nomeErro[81]="N";
	for (int i = 0; i < 81; i++) {
		strcat(nomeErro, "N");
	}
	Usuario* Matheus = novo_u(0,"Matheus");
	Usuario* user = novo_u(1,"Matheus");
	atribui_u(Matheus,-1,"Matheus Correia");
	atribui_u(Matheus,10,nomeErro);
	atribui_u(Matheus,1,"Matheus");
	if(Matheus != NULL){
		acessa_u(Matheus,&id,nome);
		if(id == 0 && strcmp(nome,"Matheus") == 0){
			printf("[Passou 0.1] - Teste da função atribui_u() com dados inválidos!\n");
			pontuacao=0.1;
		}
		else{
			printf("[Falhou 0.00] - Teste da função atribui_u() com dados inválidos!\n");
		}

	}
	else{
			printf("[Falhou 0.00] - Teste da função atribui_u() com dados inválidos!\n");
	}
	libera_u(Matheus);
	libera_u(user);
	return pontuacao;
}

float testeAtribuiUsuarioComDadosNulos(){

	float pontuacao;
	int id;
	char nome[81];
	Usuario* Matheus = novo_u(0,"Matheus");
	atribui_u(Matheus,1,NULL);
	if(Matheus != NULL){
		acessa_u(Matheus,&id,nome);
		if(id == 0 && strcmp(nome,"Matheus") == 0){
			printf("[Passou 0.1] - Teste da função atribui_u() com dados nulos!\n");
			pontuacao=0.1;
		}
		else{
			printf("[Falhou 0.00] - Teste da função atribui_u() com dados nulos!\n");
		}

	}
	else{
			printf("[Falhou 0.00] - Teste da função atribui_u() com dados nulos!\n");
	}
	libera_u(Matheus);
	return pontuacao;
}
float testeBuscaAmigoComDadosValidos(){
	float pontuacao=0.0;
	int id;
	char nome[81];
	
	Usuario* Matheus = novo_u(1,"Matheus");
	Usuario* A = novo_u(2,"A");
	Usuario* B = novo_u(3,"B");
	Usuario* C = novo_u(4,"C");
	adiciona_amigo_u(Matheus,A);
	adiciona_amigo_u(Matheus,B);
	adiciona_amigo_u(Matheus,C);
	if(Matheus != NULL && A != NULL && B != NULL && C != NULL){
		acessa_u(busca_amigo_u(Matheus,3),&id,nome);
		if(id == 3 && strcmp(nome,"B")==0){
			printf("[Passou 0.1] - Teste da função busca_amigo_u() com dados válidos!\n");
			pontuacao=0.1;
		}
		else{
			printf("[Falhou 0.00] - Teste da função busca_amigo_u() com dados válidos!\n");
		}
	}
	else{
			printf("[Falhou 0.00] - Teste da função busca_amigo_u() com dados válidos!\n");
	}

	libera_u(Matheus);
	libera_u(A);
	libera_u(B);
	libera_u(C);
	return pontuacao;
}

float testeBuscaAmigoComDadosInvalidos(){
	float pontuacao=0.0;
	int id;
	char nome[81];
	
	Usuario* Matheus = novo_u(1,"Matheus");
	Usuario* A = novo_u(2,"A");
	Usuario* B = novo_u(3,"B");
	Usuario* C = novo_u(4,"C");
	adiciona_amigo_u(Matheus,A);
	adiciona_amigo_u(Matheus,B);
	adiciona_amigo_u(Matheus,C);
	if(Matheus != NULL && A != NULL && B != NULL && C != NULL){
		if(busca_amigo_u(Matheus,-3) == NULL){
			printf("[Passou 0.1] - Teste da função busca_amigo_u() com dados inválidos!\n");
			pontuacao=0.1;
		}
		else{
			printf("[Falhou 0.00] - Teste da função busca_amigo_u() com dados inválidos!\n");
		}
	}
	else{
			printf("[Falhou 0.00] - Teste da função busca_amigo_u() com dados inválidos!\n");
	}

	libera_u(Matheus);
	libera_u(A);
	libera_u(B);
	libera_u(C);
	return pontuacao;
}

float testeAdicionarViagemComDadosValidos(){
	float pontuacao=0.0;
	int id;
	char nome[81];
	char cidade[61], pais[31], cidade2[61], pais2[31];
	int dia,mes,ano,periodo,id_v, dia2,mes2,ano2,periodo2,id_v2;
	Usuario* Matheus = novo_u(1,"Matheus");

	Viagem* viagem1 = nova_v(23,01,2017,"Fortaleza","Brasil",10);
	Viagem* viagem2 = nova_v(23,05,2017,"Fortaleza","Brasil",10);
	Viagem* viagem3 = nova_v(23,07,2017,"Fortaleza","Brasil",10);
	Viagem* viagem4 = nova_v(23,10,2017,"Fortaleza","Brasil",10);
	Viagem* viagem5 = nova_v(23,04,2017,"Fortaleza","Brasil",10);
	Viagem* viagem6 = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	Viagem** viagens = {viagem1,viagem2,viagem3,viagem4,viagem5,viagem6};

	adiciona_viagem_u(Matheus,viagem4);
	adiciona_viagem_u(Matheus,viagem6);
	adiciona_viagem_u(Matheus,viagem1);
	adiciona_viagem_u(Matheus,viagem2);
	adiciona_viagem_u(Matheus,viagem5);
	adiciona_viagem_u(Matheus,viagem3);
	Viagem** vetor = listar_viagens_u(Matheus);

	int j = 0;
	int erro = 0;
	while(j<6 && erro == 0){
		if(vetor[j] != viagens[j]){
			erro == 1;
		}
		j++;
	}
	if(Matheus != NULL){
		if(erro == 0){
			printf("[Passou 0.1] - Teste da função adiciona_viagem_u() com dados válidos!\n");
			pontuacao = 0.01;
		}
		else{
			printf("[Falhou 0.00] - Teste da função adiciona_viagem_u() com dados válidos!\n");
		}
	}
	else{
			printf("[Falhou 0.00] - Teste da função adiciona_viagem_u() com dados válidos!\n");
	}
	libera_u(Matheus);
	return pontuacao;
}


float testeAdicionarViagemComDadosInvalidos(){
	float pontuacao=0.0;
	int id;
	char nome[81];
	char cidade[61], pais[31], cidade2[61], pais2[31];
	int dia,mes,ano,periodo,id_v, dia2,mes2,ano2,periodo2,id_v2;
	Usuario* Matheus = novo_u(1,"Matheus");

	Viagem* viagem1 = nova_v(23,01,-2017,"Fortaleza","Brasil",10);
	Viagem* viagem2 = nova_v(23,-1,2017,"Fortaleza","Brasil",10);
	Viagem* viagem3 = nova_v(-31,01,2017,"Fortaleza","Brasil",10);
	Viagem* viagem4 = nova_v(31,13,2017,"Fortaleza","Brasil",10);
	Viagem* viagem5 = nova_v(23,13,2017,"Fortaleza","Brasil",10);
	Viagem* viagem6 = nova_v(23,-12,2017,"Fortaleza","Brasil",10);

	adiciona_viagem_u(Matheus,viagem4);
	adiciona_viagem_u(Matheus,viagem6);
	adiciona_viagem_u(Matheus,viagem1);
	adiciona_viagem_u(Matheus,viagem2);
	adiciona_viagem_u(Matheus,viagem5);
	adiciona_viagem_u(Matheus,viagem3);
	Viagem** vetor = listar_viagens_u(Matheus);

	if(Matheus != NULL){
		if(vetor == NULL){
			printf("[Passou 0.1] - Teste da função adiciona_viagem_u() com dados inválidos!\n");
			pontuacao = 0.01;
		}
		else{
			printf("[Falhou 0.00*] - Teste da função adiciona_viagem_u() com dados inválidos!\n");
		}
	}
	else{
			printf("[Falhou 0.00**] - Teste da função adiciona_viagem_u() com dados inválidos!\n");
	}
	libera_u(Matheus);
	return pontuacao;
}
float testeAtribuiDireitaComDadosValidos(){
	float pontuacao;
	char cidade[61], pais[31];
	int dia,mes,ano,periodo,id_v;
	Viagem* viagem1 = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	Viagem* viagem2 = nova_v(23,12,2018,"Fortaleza","Brasil",10);

	atribui_direita_v(viagem1,viagem2);
	acessa_v(acessa_direita_v(viagem1),&dia,&mes,&ano,cidade,pais,&periodo,&id_v);
	if(dia == 23 && mes == 12 && ano == 2018 && strcmp("Fortaleza",cidade) == 0 && strcmp(pais,"Brasil") == 0 && periodo == 10){
		printf("[Passou 0.1] - Teste da função atribui_direita_v() com dados válidos!\n");
		pontuacao = 0.01;
	}
	else{
			printf("[Falhou 0.00] - Teste da função atribui_direita_v() com dados válidos!\n");
	}
}

float testeAtribuiEsquerdaComDadosValidos(){
	float pontuacao;
	char cidade[61], pais[31];
	int dia,mes,ano,periodo,id_v;
	Viagem* viagem1 = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	Viagem* viagem2 = nova_v(23,12,2018,"Fortaleza","Brasil",10);

	atribui_esquerda_v(viagem1,viagem2);
	acessa_v(acessa_esquerda_v(viagem1),&dia,&mes,&ano,cidade,pais,&periodo,&id_v);
	if(dia == 23 && mes == 12 && ano == 2018 && strcmp("Fortaleza",cidade) == 0 && strcmp(pais,"Brasil") == 0 && periodo == 10){
		printf("[Passou 0.1] - Teste da função atribui_esquerda_v() com dados válidos!\n");
	}
	else{
			printf("[Falhou 0.00] - Teste da função atribui_esquerda_v() com dados válidos!\n");
	}
}

float testeMinimoComDadosValidos(){
	float pontuacao;
	char cidade[61], pais[31];
	int dia,mes,ano,periodo,id_v;
	Viagem* viagem1 = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	Viagem* viagem2 = nova_v(23,12,2018,"Fortaleza","Brasil",10);
	Viagem* viagem3 = nova_v(23,12,2019,"Fortaleza","Brasil",10);
	atribui_esquerda_v(viagem1,viagem2);
	atribui_direita_v(viagem1,viagem3);
	acessa_v(Minimo(viagem1),&dia,&mes,&ano,cidade,pais,&periodo,&id_v);
	if(dia == 23 && mes == 12 && ano == 2018 && strcmp("Fortaleza",cidade) == 0 && strcmp(pais,"Brasil") == 0 && periodo == 10){
		printf("[Passou 0.1] - Teste da função Minimo() com dados válidos!\n");
	}
	else{
		printf("[Falhou 0.00] - Teste da função Minimo() com dados válidos!\n");
	}
	return pontuacao;
}

float testeSucessorComDadosValidos(){
	float pontuacao;
	char cidade[61], pais[31];
	int dia,mes,ano,periodo,id_v;
	Viagem* viagem1 = nova_v(23,12,2017,"Fortaleza","Brasil",10);
	Viagem* viagem2 = nova_v(23,12,2018,"Fortaleza","Brasil",10);
	Viagem* viagem3 = nova_v(23,12,2019,"Fortaleza","Brasil",10);
	atribui_esquerda_v(viagem1,viagem2);
	atribui_direita_v(viagem1,viagem3);
	acessa_v(Sucessor(viagem1),&dia,&mes,&ano,cidade,pais,&periodo,&id_v);
	if(dia == 23 && mes == 12 && ano == 2019 && strcmp("Fortaleza",cidade) == 0 && strcmp(pais,"Brasil") == 0 && periodo == 10){
		printf("[Passou 0.1] - Teste da função Sucessor() com dados válidos!\n");
		pontuacao = 0.01;
	}
	else{
		printf("[Falhou 0.00] - Teste da função Sucessor() com dados válidos!\n");
	}
}

float testeRemoverViagemComDadosValidos(){
	float pontuacao=0.0;
	int id;
	char nome[81];
	char cidade[61], pais[31], cidade2[61], pais2[31];
	int dia,mes,ano,periodo,id_v, dia2,mes2,ano2,periodo2,id_v2;
	Usuario* Matheus = novo_u(1,"Matheus");

	Viagem* viagem1 = nova_v(1,01,2017,"Fortaleza","Brasil",10);
	Viagem* viagem2 = nova_v(2,02,2017,"Fortaleza","Brasil",10);
	Viagem* viagem3 = nova_v(3,03,2017,"Fortaleza","Brasil",10);
	Viagem* viagem4 = nova_v(4,04,2017,"Fortaleza","Brasil",10);
	Viagem* viagem5 = nova_v(5,05,2017,"Fortaleza","Brasil",10);
	Viagem* viagem6 = nova_v(6,06,2017,"Fortaleza","Brasil",10);
	adiciona_viagem_u(Matheus,viagem4);
	adiciona_viagem_u(Matheus,viagem2);
	adiciona_viagem_u(Matheus,viagem1);
	
	adiciona_viagem_u(Matheus,viagem3);
	
	adiciona_viagem_u(Matheus,viagem5);
	adiciona_viagem_u(Matheus,viagem6);

	Viagem** vetor = listar_viagens_u(Matheus);

	remover_viagem_u(Matheus,0);
	remover_viagem_u(Matheus,5);
	remover_viagem_u(Matheus,6);
	remover_viagem_u(Matheus,3);
	remover_viagem_u(Matheus,4);
	remover_viagem_u(Matheus,1);
	remover_viagem_u(Matheus,2);
	
	//vetor = listar_viagens_u(Matheus);
/*	if(vetor != NULL){
		remover_viagem_u(Matheus,0);
		remover_viagem_u(Matheus,1);
		remover_viagem_u(Matheus,2);
		remover_viagem_u(Matheus,3);
		remover_viagem_u(Matheus,4);
		remover_viagem_u(Matheus,5);
		vetor = listar_viagens_u(Matheus);
		if(vetor == NULL){
			printf("[Passou 0.1] - Teste da função remover_viagem_u() com dados válidos!\n");
			pontuacao = 0.1;
		}
		else{
			printf("[Falhou 0.00] - Teste da função remover_viagem_u() com dados válidos!\n");
		}
	}
	else{
			printf("[Falhou 0.00] - Teste da função remover_viagem_u() com dados válidos!\n");
	}*/
	return pontuacao;
}
int main(){
/*	printf("Funções de Viajem\n\n");
	testeNovoComDadosValidos();
	testeNovoComDadosInvalidos();
	testeNovoComDadosNulos();
	testeAcessa();
	testeAtribuiComDadosValidos();
	testeAtribuiComDadosValidos();
	testeAtribuiComDadosInvalidos();
	testeAtribuiComDadosNulos();
	testeLiberaComDadosValidos();
	testeMinimoComDadosValidos();
	testeAtribuiDireitaComDadosValidos();
	testeAtribuiEsquerdaComDadosValidos();
	testeSucessorComDadosValidos();
	printf("\n\nFunções do usuário\n\n");
	testeNovoUsuarioComDadosValidos();
	testeNovoUsuarioComDadosInvalidos();
	testeLiberarUsuarioComDadosValidos();
	testeAdicionaAmigosComDadosValidos();
	testeAdicionaAmigosComDadosInvalidos();
	testeAdicionaAmigosComDadosNulos();
	testeRemoverAmigoComDadosValidos();
	testeAtribuiUsuarioComDadosValidos();
	testeListarAmigosComDadosValidos();
	testeAtribuiUsuarioComDadosInvalidos();
	testeAtribuiUsuarioComDadosNulos();
	testeBuscaAmigoComDadosValidos();
	testeBuscaAmigoComDadosInvalidos();
	testeAdicionarViagemComDadosValidos();
	testeAdicionarViagemComDadosInvalidos();*/
	testeRemoverViagemComDadosValidos();
	return 0;
}
