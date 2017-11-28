#include <stdlib.h>
#include <stdio.h>
#include "Viagem.h"
#include <string.h>
struct viagem{
	int id;
	int dia;
	int mes;
	int ano;
	char cidade[60];
	char pais[30];
	int periodo;
	Viagem *direita, *esquerda, *pai;
};
Viagem *nova_v(int dia, int mes, int ano, char *cidade, char *pais, int periodo){
	if(id<0 || (dia<1 || dia>31) || (mes<1 || mes>12) || ano<1 || cidade==NULL || pais==NULL || periodo<1){
		return NULL;
	}
	else{
		if(strlen(pais)<30 && strlen(cidade)<60){
			Viagem* v = (Viagem*) malloc(sizeof(Viagem));
			if(v==NULL){
				return NULL;
			}
			v->id = id;
			v->dia = dia;
			v->mes = mes;
			v->ano = ano;
			strcpy(v->cidade, cidade);
			strcpy(v->pais, pais);
			v->periodo = periodo;
			return v;
		}
		return NULL;
	}
}

void libera_v(Viagem *viagem){
	if(viagem!=NULL){
		Viagem viagemVazia;
		*viagem = viagemVazia;
		libera_v(viagem->esquerda)
		libera_v(viagem->direita)
		free(viagem);
		viagem=NULL;
	}
}

void acessa_v(Viagem *viagem, int *dia, int *mes, int *ano, char *cidade, char *pais, int *periodo){
	if(viagem!=NULL){
		*dia = viagem->dia;
		*mes = viagem->mes;
		*ano = viagem->ano;
		*periodo = viagem->periodo;
		strcpy(cidade, viagem->cidade);
		strcpy(pais,viagem->pais);
	}
} 

void atribui_v(Viagem *viagem, int dia, int mes, int ano, char *cidade, char *pais, int periodo){
	if((dia=>1 && dia<=31) && (mes>=1 && mes<=12) && ano>=1 && cidade!=NULL && pais!=NULL && periodo>=1){
		if(strlen(pais)<30 && strlen(cidade)<60){
			viagem->dia = dia;
			viagem->mes = mes;
			viagem->ano = ano;  
			v->periodo = periodo;
			strcpy(v->cidade, cidade);
			strcpy(v->pais, pais);
		}
	}
} 
/*Atribui a um nó viagem um filho direito*/
void atribui_direita_v(Viagem *viagem, Viagem *direita){
	if(viagem!=NULL){
		viagem->direita = direita;
		if(direita!=NULL){
			direita->pai = viagem;
		}

	}
} 
/*A função retorna o nó viagem que é direita do nó dado*/
Viagem *acessa_direita_v(Viagem *viagem){
	if(viagem!=NULL){
		return viagem->direita;
	}
} 
/*Atribui a um nó viagem um filho esquerdo*/
void atribui_esquerda_v(Viagem *viagem, Viagem *esquerda){
	if(viagem!=NULL){
		viagem->esquerda = esquerda;
		if(direita!=NULL){
			direita->pai = viagem;
		}

	}
} 
/*A função retorna o nó viagem que é esquerda do nó dado*/
Viagem *acessa_esquerda_v(Viagem *viagem){
	if(viagem!=NULL){
		return viagem->esquerda;
	}
} 

int tamanho_v(){
	return sizeof(Viagem);
}