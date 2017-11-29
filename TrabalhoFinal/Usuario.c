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
		if(pos!=-1){
			remove_amigo_u(amigo, usuario->id);
		}
		
		
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
/*Retorna 1 se data1<data2 e 0 se data1>data2*/
int checkData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
	int diaMes[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	return (dia1+diaMes[mes1]*mes1+ano1*365)<(dia2+diaMes[mes2]*mes2+ano2*365);

}
/*A data1 tem prioridade enquanto a data2 é a que eu quero adicionar*/
int conflitoData(int dia1, int mes1, int ano1,int periodo1, int dia2, int mes2, int ano2,int periodo2){
	if(checkData(dia1,mes1,ano1,dia2,mes2,ano2)==1){ /*Verifica se a data1 é menor que a data 1*/
		if(checkData(dia1+periodo1,mes1,ano1,dia2,mes2,ano2)==1){ /*Verifica se a data1+periodo1 é menor que a data2*/
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(checkData(dia2+periodo2,mes2,ano2,dia1,mes1,ano1)==1){ /*Verifica se a data2+periodo2 é menor que data1*/
		return 0;
	}
	else{
		return 1;
	}

}

void adiciona_viagem_u(Usuario *usuario, Viagem *viagem){
	int* dia1,dia2,mes1,mes2,ano1,ano2,periodo1,periodo2;
	int conflito=0;
	char cidade[61],pais[31];
	if(usuario!=NULL && viagem!=NULL){
		Viagem pai = NULL;
		Viagem raiz = usuario->viagens;
		acessa_v(viagem,dia2,mes2,ano2,cidade,pais,periodo2);
		while(raiz!=NULL && conflito==0){
			pai=raiz;
			acessa_v(raiz,dia1,mes1,ano1,cidade,pais,periodo1);
			if(conflitoData(dia1,mes1,ano1,periodo1,dia2,mes2,ano2,periodo2)!=1){
				/*(1)raiz<viagem*/
				if(checkData(dia1,mes1,ano1,dia2,mes2,ano2)==1){
					/*Se a afirmação (1) é verdadeira*/
					raiz=acessa_direita_v(raiz);
				}
				else{
					raiz=acessa_esquerda_v(raiz);
				}

			}
			else{
				conflito=1;
			}
		}
		if(conflito==0){
			acessa_v(pai,dia1,mes1,ano1,cidade,pais,periodo1);
			atribui_pai_v(viagem,pai)
			if(pai==NULL){
				usuario->viagem=viagem
			}
			else if(checkData(dia2,mes2,ano2,dia1,mes1,ano1)){
				atribui_esquerda_v(pai,viagem);
			}
			else{
				atribui_direita_v(pai,viagem);
			}
		}

	}
}