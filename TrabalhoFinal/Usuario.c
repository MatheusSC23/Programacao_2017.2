#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Usuario.h"

struct usuario{
	int id,primeiro,ultimo,tamanho;
	char nome[80];
	Usuario **amigos;
	Viagem *viagens;
};

Usuario *novo_u(int id, char *nome){
	if(nome != NULL && id>=0 && nome!=NULL && strlen(nome)<80){
		Usuario* usuario = (Usuario*) malloc(sizeof(Usuario));
		if(usuario==NULL){
			return NULL;
		}
		Usuario** amigos = (Usuario**) malloc(10*sizeof(Usuario));
		if(amigos==NULL){
			return NULL;
		}
		usuario->nome = nome;
		usuario->id = id;
		usuario->amigos = amigos;
		usuario->viagens = NULL;
		usuario->primeiro = -1;
		usuario->ultimo = -1;
		usuario->tamanho = 10;
		return usuario;
	}
	return NULL;
}

void libera_u(Usuario *usuario){
	if(usuario!=NULL){
		libera_v(usuario->viagens);
		Usuario vazio;
		for(int i = primeiro; i<=ultimo; i++){
			usuario->amigos[i]=vazio;
			free(usuario->amigos[i]);
			usuario->amigos[i]=NULL;
		}
		*usuario=vazio;
		free(usuario);
		usuario=NULL;
	}
}

void acessa_u(Usuario *usuario, int *id, char *nome){
	if(usuario!=NULL){
		*id = usuario->id;
		strcpy(nome,usuario->nome);
	}
} 

void atribui_u(Usuario *usuario, int id, char *nome){
	if(usuario!=NULL && id>=0 && nome!=NULL && strlen(nome)<80){
		usuario->id = id;
		strcpy(usuario->nome,nome);
	}
}

void adiciona_amigo_u(Usuario *usuario, Usuario *amigo){
	if(usuario!=NULL && amigo!=NULL){
		if(usuario->tamanho<(usuario->tamanho+1)){
			usuario->amigos=(Usuario**) realloc(usuario->amigos,(usuario->tamanho+10)*sizeof(Usuario);
			usuario->tamanho+=10;
		}
		if(usuario->primeiro==-1 && usuario->ultimo==-1){
			usuario->primeiro++;
			usuario->ultimo++;
			usuario->amigos[primeiro]=amigo;
		}
		else{
			usuario->ultimo++;
			usuario->amigos[usuario->ultimo]=amigo;
		}
	}
}