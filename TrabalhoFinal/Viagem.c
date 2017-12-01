#include <stdlib.h>
#include <stdio.h>
#include "Viagem.h"
#include <string.h>
int id_viagem=0;
struct viagem{
	int id;
	int dia;
	int mes;
	int ano;
	char cidade[61];
	char pais[31];
	int periodo;
	Viagem *direita, *esquerda, *pai;
};
Viagem *nova_v(int dia, int mes, int ano, char *cidade, char *pais, int periodo){
	if((dia<1 || dia>31) || (mes<1 || mes>12) || ano<1 || cidade==NULL || pais==NULL || periodo<1){
		return NULL;
	}
	else{
		if(strlen(pais)<31 && strlen(cidade)<61){
			Viagem* v = (Viagem*) malloc(sizeof(Viagem));
			if(v==NULL){
				return NULL;
			}

			id_viagem++;
			v->id = id_viagem;
			v->dia = dia;
			v->mes = mes;
			v->ano = ano;
			strcpy(v->cidade, cidade);
			strcpy(v->pais, pais);
			v->periodo = periodo;
			v->direita=NULL;
			v->esquerda=NULL;
			return v;
		}
		return NULL;
	}
}

void libera_v(Viagem *viagem){
	if(viagem!=NULL){
		Viagem viagemVazia;
		*viagem = viagemVazia;
		free(viagem);
		viagem=NULL;
	}
}

void acessa_v(Viagem *viagem, int *dia, int *mes, int *ano, char *cidade, char *pais, int *periodo, int *id){
	if(viagem!=NULL){
		*dia = viagem->dia;
		*mes = viagem->mes;
		*ano = viagem->ano;
		*periodo = viagem->periodo;
		*id = viagem->id;
		strcpy(cidade, viagem->cidade);
		strcpy(pais,viagem->pais);
	}
} 

void atribui_v(Viagem *viagem, int dia, int mes, int ano, char *cidade, char *pais, int periodo){
	if((dia>0 && dia<=31) && (mes>=1 && mes<=12) && ano>=1 && cidade!=NULL && pais!=NULL && periodo>=1){
		if(strlen(pais)<31 && strlen(cidade)<61){
			viagem->dia = dia;
			viagem->mes = mes;
			viagem->ano = ano;  
			viagem->periodo = periodo;
			strcpy(viagem->cidade, cidade);
			strcpy(viagem->pais, pais);
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
	return NULL;
} 
/*Atribui a um nó viagem um filho esquerdo*/
void atribui_esquerda_v(Viagem *viagem, Viagem *esquerda){
	if(viagem!=NULL){
		viagem->esquerda = esquerda;
		if(esquerda!=NULL){
			esquerda->pai = viagem;
		}

	}
} 
/*A função retorna o nó viagem que é esquerda do nó dado*/
Viagem *acessa_esquerda_v(Viagem *viagem){
	if(viagem!=NULL){
		return viagem->esquerda;
	}
	return NULL;
} 

void atribui_pai_v(Viagem *viagem, Viagem *pai){
	if(viagem!=NULL){
		viagem->pai = pai;
	}
}
Viagem *acessa_pai_v(Viagem *viagem){
	if(viagem!=NULL){
		return viagem->pai;
	}
	return NULL;
}
Viagem *Minimo(Viagem* viagem){
	Viagem* retorno = viagem;
	while(acessa_esquerda_v(viagem)!=NULL){
		retorno=acessa_esquerda_v(retorno);
	}
	return retorno;
}
Viagem *Sucessor(Viagem* viagem){
	if(acessa_direita_v(viagem)!=NULL){
		return Minimo(viagem);
	}
	Viagem *retorno=acessa_pai_v(viagem);
	while(retorno!=NULL && viagem==acessa_direita_v(retorno)){
		viagem=retorno;
		retorno=acessa_pai_v(viagem);

	}
	return retorno;
}

void Transplantar(Viagem* viagem1, Viagem* viagem2){
	if(acessa_pai_v(viagem1) == NULL){
		viagem1 = viagem2;
	}
	else if(viagem1 == acessa_esquerda_v(acessa_pai_v(viagem1))){
		atribui_esquerda_v(acessa_pai_v(viagem1),viagem2);
	}
	else{
		atribui_direita_v(acessa_pai_v(viagem1),viagem2);
	}
	if(viagem2!=NULL){
		atribui_pai_v(viagem2,acessa_pai_v(viagem1));
	}
}
void Remover(Viagem* viagem){
	if(viagem!=NULL){
		if(acessa_esquerda_v(viagem)==NULL){
			Transplantar(viagem,acessa_direita_v(viagem));
		}
		else if(acessa_direita_v(viagem)==NULL){
			Transplantar(viagem,acessa_esquerda_v(viagem));
		}
		else{
			Viagem* sucessor = Minimo(acessa_direita_v(viagem));
			if(acessa_pai_v(sucessor)!=viagem){
				Transplantar(sucessor,acessa_direita_v(sucessor));
				atribui_direita_v(sucessor, acessa_direita_v(viagem));
				atribui_pai_v(acessa_direita_v(viagem),sucessor);
			}
			Transplantar(viagem,sucessor);
			atribui_esquerda_v(sucessor,acessa_esquerda_v(viagem));
			atribui_pai_v(acessa_esquerda_v(sucessor),sucessor);
		}
	}
	
}
int tamanho_v(){
	return sizeof(Viagem);
}
