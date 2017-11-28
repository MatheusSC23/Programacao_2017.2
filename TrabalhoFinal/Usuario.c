#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Usuario.h"

struct usuario{
	int id,primeiro,ultimo,tamanho;
	char nome[81];
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
			remove_amigo_u(usuario->amigos[i],usuario->id);
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
	int usuario_id;
	char nome[81];
	acessa_u(amigo,usuario_id,nome);
	Usuario NaLista = busca_amigo_u(usuario,amigo)
	if(usuario!=NULL && amigo!=NULL && usuario->id!=usuario_id && NaLista==NULL){
		if(usuario->tamanho<(usuario->tamanho+1)){
			Usuario** amigos = (Usuario**) realloc(usuario->amigos,(usuario->tamanho+10)*sizeof(Usuario);
			usuario->amigos = amigos;
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
		adiciona_amigo_u();
	}
}

void remove_amigo_u(Usuario *usuario, int id){
	if(usuario!=NULL && id>=0 && usuario->primeiro!=-1){
		int i=0;
		int pos = -1;
		int usuario_id;
		char nome[81];
		Usuario amigo=NULL;
		while(i<=usuario->ultimo && pos==-1 ){
			acessa_u(usuario->amigos[i],usuario_id,nome);
			if(usuario_id==id){
				amigo=usuario->amigos[i];
				pos=i;
				usuario->amigos[i]=NULL;
			}
			i++;
		}
		if(usuario->ultimo>pos){
			while(pos<usuario->ultimo){
				usuario->amigos[pos]=usuario->amigos[pos+1];
				usuario->amigos[pos+1]=NULL;
			}
		}
		else if(usuario->ultimo==usuario->primeiro){
			usuario->ultimo--;
			usuario->primeiro--;
		}
		else{
			usuario->ultimo--;
		}
		remove_amigo_u(amigo, usuario->id);
		
	}
}

Usuario *busca_amigo_u(Usuario *usuario, int id){
	if(usuario!=NULL && id>=0){
		int i = 0;
		char nome[81];
		int usuario_id;
		Usuario retorno=NULL;
		while(i<=usuario->ultimo && retorno==NULL){
			acessa_u(usuario->amigos[i],usuario_id,nome);
			if(usuario_id==id){
				retorno=usuario->amigos[i];
			}
			i++;
		}
		return retorno;
	}
	return NULL;
}

Usuario *lista_amigos_u(Usuario *usuario){
	if(usuario!=NULL){
		return usuario->amigos;
	}
}

void adiciona_viagem_u(Usuario *usuario, Viagem *viagem){
	if(usuario!=NULL && viagem!=NULL){
		Viagem pai = NULL;
		Viagem raiz = usuario->viagens;
		while(){

		}
	}
}