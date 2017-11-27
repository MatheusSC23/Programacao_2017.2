#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Usuario.h"

struct	usuario{
	int id;
	char nome[51];
	Usuario *amigos,*proximo,*anterior;
	Viagem *viagens;
};

Usuario	*novo_u(int	id,	char	*nome){
	if(nome != NULL && id>1){
		Usuario* usuario = (Usuario*) malloc(sizeof(Usuario));
		if(usuario==NULL){
			return NULL;
		}
		Usuario* amigos = (Usuario*) malloc(sizeof(Usuario));
		if(amigos==NULL){
			return NULL;
		}
		Viagem* viagens = (Viagem*) malloc(sizeof(Usuario));
		if(viagens==NULL){
			return NULL;
		}
		usuario->nome = nome;
		usuario->id = id;
		usuario->amigos = NULL;
		usuario->viagens = NULL;
		return usuario;
	}
	return NULL;
}
void	libera_u(Usuario *usuario){
	if(usuario!=NULL){
		libera_v(usuario->viagens);
		Usuario usuarioVazio;
		usuario->amigos=usuarioVazio;
		*usuario = usuarioVazio;
		free(usuario->amigos);
		free(usuario);
		usuario=Null
	}
}