#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Usuario.h"

struct usuario{
	int id,primeiro,ultimo,tamanho;
	int numeroViagens;
	char nome[81];
	Usuario **amigos;
	Viagem *viagens;
};

Usuario** usuarioGlobal = NULL;//Vertor contendo todos os usuários
int tamanhoGlobal = 10;//Tamanho do verto usarioGlobal
int posUltimo = -1; //Posição do último usuário criado

//Funções do usuarioGlobal
void adicionarGlobal(Usuario* usuario){
	if(usuario != NULL){
		if(usuarioGlobal == NULL){ //Verifica se o usuário já foi alocado
			usuarioGlobal = (Usuario**) malloc(tamanhoGlobal*tamanho_u()); //Aloca o vetor usuarioGlobal
		}
		else if(posUltimo+1>=tamanhoGlobal){ //Verifica se usuarioGlobal está cheio
			tamanhoGlobal += 10;
			usuarioGlobal = (Usuario**) realloc(usuarioGlobal,tamanhoGlobal*tamanho_u()); //Realoca usuarioGlobal
		}
		posUltimo++; //Soma a posição
		usuarioGlobal[posUltimo] = usuario; //Adiciona usuário no novo último
	}
}

//Função que verifica se o id já está sendo usado e retorna 1 se sim e 0 caso contrário
int idExiste(int id){
	if(id>=0){
		if(posUltimo<=-1){
			return 0;
		}
		else{
			int idExiste = 0;
			int j = 0;
			int idCopia;
			char nome[81];
			while(idExiste == 0 && j<=posUltimo){
				acessa_u(usuarioGlobal[j],&idCopia,nome);
				if(id == idCopia){
					idExiste = 1;
				}
				j++;
			}
			return idExiste;
		}
	}
	return 0;
}

//Função que remove um usuario de usuarioGlobal
void removerGlobal(Usuario* usuario){
	if(usuario != NULL && posUltimo>-1){
		if(posUltimo == 0){
			if(usuario == usuarioGlobal[posUltimo]){
				usuarioGlobal[posUltimo] = NULL;
				posUltimo--;
			}
		}
		else{
			int j = 0;
			int achado = 0;
			int id;
			char nome[81];
			while(j<=posUltimo && achado == 0){
				acessa_u(usuarioGlobal[j],&id,nome);
				if(id == usuario->id){
					achado = 1;
				}
				j++;
			}
			if(achado == 1){
				for(int i = j-1; i<posUltimo; i++){
					usuarioGlobal[i] = usuarioGlobal[i+1];
					usuarioGlobal[i+1] = NULL;					
				}
				posUltimo--;
			}
		}
	}
	
}


Usuario *novo_u(int id, char *nome){
	if(nome != NULL && id>=0 && nome!=NULL && strlen(nome)<81){
		if(idExiste(id)){
			return NULL;
		}

		Usuario* usuario = (Usuario*) malloc(sizeof(Usuario));
		if(usuario==NULL){
			return NULL;
		}
		Usuario** amigos = (Usuario**) malloc(10*sizeof(Usuario));
		if(amigos==NULL){
			return NULL;
		}
		strcpy(usuario->nome,nome);
		usuario->id = id;
		usuario->amigos = amigos;
		usuario->viagens = NULL;
		usuario->primeiro = -1;
		usuario->ultimo = -1;
		usuario->tamanho = 10;
		usuario->numeroViagens = 0;
		adicionarGlobal(usuario);
		return usuario;
	}
	return NULL;
}

void libera_u(Usuario *usuario){
	if(usuario!=NULL){
		removerGlobal(usuario);
		libera_v(usuario->viagens);
		Usuario vazio;
		Usuario* amigo;
		int id;
		char nome[81];

		if(usuario->primeiro != -1){
			while(usuario->primeiro>=0){
				amigo = usuario->amigos[0];
				acessa_u(amigo,&id,nome);
				remove_amigo_u(usuario,id);
			}
		}
		
		free(usuario->amigos);
		usuario->amigos=NULL;
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
	if(usuario!=NULL && id>=0 && nome!=NULL && strlen(nome)<81){
		if(id == usuario->id){
			strcpy(usuario->nome,nome);	
		}
		else{
			if(!idExiste(id)){
				strcpy(usuario->nome,nome);
				usuario->id = id;
			}
		}
	}
}

void adiciona_amigo_u(Usuario *usuario, Usuario *amigo){
	if(usuario!=NULL && amigo!=NULL){
		int usuario_id;
		char nome[81];
		acessa_u(amigo,&usuario_id,nome);/*Passa o id do amigo para usuario_id*/
		if(usuario->id!=usuario_id && busca_amigo_u(usuario, usuario_id)==NULL){
			if(usuario->tamanho<(usuario->tamanho+1)){
				Usuario** amigos = (Usuario**) realloc(usuario->amigos,usuario->tamanho+10*sizeof(Usuario));
				usuario->amigos = amigos;
				usuario->tamanho+=10;
			}
			if(usuario->primeiro==-1 && usuario->ultimo==-1){
				usuario->primeiro++;
				usuario->ultimo++;
				usuario->amigos[usuario->primeiro]=amigo;
			}
			else{
				usuario->ultimo++;
				usuario->amigos[usuario->ultimo]=amigo;
			}
			adiciona_amigo_u(amigo,usuario);
		}
	}
}

void remove_amigo_u(Usuario *usuario, int id){
	int i=0;
	int pos = -1;
	int usuario_id;
	char nome[81];
	Usuario *amigo;
	if(usuario!=NULL && id>=0 && usuario->primeiro!=-1){
		while(i<=usuario->ultimo && pos==-1 ){
			acessa_u(usuario->amigos[i],&usuario_id,nome);
			if(usuario_id==id){
				amigo=usuario->amigos[i];
				pos=i;
			}
			i++;
		}
		if(amigo!=NULL && pos>-1){
			if(usuario->ultimo>pos){
				while(pos<usuario->ultimo){
					usuario->amigos[pos]=usuario->amigos[pos+1];
					usuario->amigos[pos+1]=NULL;
					pos++;
				}
				usuario->ultimo--;
			}
			else if(usuario->ultimo==usuario->primeiro){
				usuario->ultimo--;
				usuario->primeiro--;
				usuario->amigos[0] = NULL;
			}
			else if(pos == usuario->ultimo){
				usuario->amigos[pos] = NULL;
				usuario->ultimo--;
			}
			remove_amigo_u(amigo, usuario->id);	
		}
	}
}

Usuario *busca_amigo_u(Usuario *usuario, int id){
	if(usuario!=NULL && id>=0){
		int i = 0;
		char nome[81];
		int usuario_id;
		Usuario *retorno=NULL;
		while(i<=usuario->ultimo && retorno==NULL){
			acessa_u(usuario->amigos[i],&usuario_id,nome);
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
	if(usuario!=NULL && usuario->primeiro!=-1){
		Usuario** amigosCopia = (Usuario**) malloc((usuario->ultimo+1)*tamanho_u());
		for(int i = usuario->primeiro; i<=usuario->ultimo; i++){
			amigosCopia[i] = usuario->amigos[i];
		}
		return amigosCopia;
	}
	return NULL;
}
/*Retorna 1 se data1<data2 e 0 se data1>data2*/
int MenorDoQue(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
	int diaMes[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	return (dia1+diaMes[mes1]*mes1+ano1*365)<(dia2+diaMes[mes2]*mes2+ano2*365);

}
/*A data1 tem prioridade enquanto a data2 é a que eu quero adicionar*/
int conflitoData(int dia1, int mes1, int ano1,int periodo1, int dia2, int mes2, int ano2,int periodo2){
	if(MenorDoQue(dia1,mes1,ano1,dia2,mes2,ano2)==1){ /*Verifica se a data1 é menor que a data 1*/
		if(MenorDoQue(dia1+periodo1,mes1,ano1,dia2,mes2,ano2)==1){ /*Verifica se a data1+periodo1 é menor que a data2*/
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(MenorDoQue(dia2+periodo2,mes2,ano2,dia1,mes1,ano1)==1){ /*Verifica se a data2+periodo2 é menor que data1*/
		return 0;
	}
	else{
		return 1;
	}

}

void adiciona_viagem_u(Usuario *usuario, Viagem *viagem){

	int dia1,dia2,mes1,mes2,ano1,ano2,periodo1,periodo2,id;
	int conflito=0;
	char cidade[61],pais[31];
	if(usuario!=NULL && viagem!=NULL){
		Viagem *pai = NULL;
		Viagem *raiz = usuario->viagens;
		acessa_v(viagem,&dia2,&mes2,&ano2,cidade,pais,&periodo2,&id);
		while(raiz!=NULL && conflito==0){
			pai=raiz;
			acessa_v(raiz,&dia1,&mes1,&ano1,cidade,pais,&periodo1,&id);
			if(conflitoData(dia1,mes1,ano1,periodo1,dia2,mes2,ano2,periodo2)!=1){
				if(MenorDoQue(dia1,mes1,ano1,dia2,mes2,ano2)==1){  /*(1)raiz<viagem*/
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
			usuario->numeroViagens++;
			acessa_v(pai,&dia1,&mes1,&ano1,cidade,pais,&periodo1,&id);
			atribui_pai_v(viagem,pai);
			if(pai==NULL){
				usuario->viagens=viagem;
			}
			else if(MenorDoQue(dia2,mes2,ano2,dia1,mes1,ano1)){
				atribui_esquerda_v(pai,viagem);
			}
			else{
				atribui_direita_v(pai,viagem);
			}
		}

	}
}
void remover_viagem_u(Usuario *usuario, int id){
	if(usuario!=NULL && id>=0){
		int dia,mes,ano,periodo,viagem_id;
		char cidade[61],pais[31];
		Viagem* viagem = usuario->viagens;
		if(viagem != NULL){
			Viagem* v1 = Minimo(viagem);
			acessa_v(v1,&dia,&mes,&ano,cidade,pais,&periodo,&viagem_id);
			while(v1 != NULL && viagem_id!=id){
				v1=Sucessor(v1);
				acessa_v(v1,&dia,&mes,&ano,cidade,pais,&periodo,&viagem_id);			
			}
			if(v1 != NULL){
				Remover(usuario->viagens,v1);
				usuario->numeroViagens--;
			}
			//Esse if verifica se a lista está vazia e cria um nó Viagem nulo e passa para usuario->viagens
			if(usuario->numeroViagens == 0){
				Viagem* novaViagem = NULL;
				usuario->viagens = novaViagem;
			}
		}
	}
}
Viagem *listar_viagens_u(Usuario *usuario){
	if(usuario!=NULL && usuario->viagens!=NULL && usuario->numeroViagens>0){
		Viagem** copiaViagem = (Viagem**) malloc(usuario->numeroViagens*tamanho_v());
		Viagem* runner = Minimo(usuario->viagens);
		int i = 0;
		while(runner != NULL){
			copiaViagem[i] = runner;
			runner = Sucessor(runner);
			i++;
		}
		return copiaViagem;
	}
	return NULL;
}

Viagem *buscar_viagem_por_data_u(Usuario *usuario, int dia, int mes, int ano){
	if(usuario!=NULL && dia>0 && dia<32 && mes>0 && mes<13 && ano>0){
		int dia1,mes1,ano1,periodo,id;
		char cidade[61],pais[31];
		Viagem *viagem = usuario->viagens;
		acessa_v(viagem,&dia1,&mes1,&ano1,cidade,pais,&periodo,&id);
		while((dia!=dia1 || mes!=mes1 || ano!=ano1) && viagem!=NULL){
			if(MenorDoQue(dia,mes,ano,dia1,mes1,ano1)){
				viagem = acessa_esquerda_v(viagem);
			}
			else{
				viagem = acessa_direita_v(viagem);
			}
			acessa_v(viagem,&dia1,&mes1,&ano1,cidade,pais,&periodo,&id);
		}
		return viagem;
	}
	return NULL;
}

Viagem *buscar_viagem_por_destino_u(Usuario *usuario, char *cidade, char *pais){
	if(usuario!=NULL && cidade!=NULL && pais!=NULL && usuario->viagens!=NULL){
		if(strlen(cidade)<61 && strlen(pais)<31){
			int dia,mes,ano,periodo, id;
			char cidade2[61],pais2[31];
			int elementos = 0;
			int index = -1;
			Viagem** ListaDeViagens = (Viagem**) malloc(1*tamanho_v());
			Viagem* viagem = Minimo(usuario->viagens);
			acessa_v(viagem,&dia,&mes,&ano,cidade2,pais2,&periodo,&id);
			while(viagem!=NULL){
				if(strcmp(cidade,cidade2)==0 && strcmp(pais,pais2)==0){
					if(index != -1){
						ListaDeViagens = (Viagem**) realloc(ListaDeViagens,(elementos+1)*tamanho_v());
					}
					index++;
					ListaDeViagens[index] = viagem;
					elementos++;
				}
				viagem=Sucessor(viagem);
				acessa_v(viagem,&dia,&mes,&ano,cidade2,pais2,&periodo,&id);
			}
			if(index == -1){
				return NULL;
			}
			return ListaDeViagens;
		}

	}
	return NULL;
} 
Viagem *filtrar_viagens_amigos_por_data_u(Usuario *usuario, int dia, int mes, int ano){
	if(usuario!=NULL && dia<32 && dia>0 && mes<32 && mes>0 && ano>0 && usuario->primeiro>-1){
		int elementos = 0;
		int index = -1;
		int dia2,mes2,ano2,periodo2,id2;
		char cidade[61],pais[31];
		Viagem** ListaDeViagens = (Viagem**) malloc(1*tamanho_v());
		for(int i = usuario->primeiro; i<=usuario->ultimo; i++){
			Usuario* amigo = usuario->amigos[i];
			if(amigo->viagens != NULL){
				Viagem* runner = Minimo(amigo->viagens);
				do{
					acessa_v(runner,&dia2,&mes2,&ano2,cidade,pais,&periodo2,&id2);
					if(dia == dia2 && mes == mes2 && ano == ano2){
						if(index != -1){
							ListaDeViagens = (Viagem**) realloc(ListaDeViagens,(elementos+1)*tamanho_v());
						}
						index++;
						ListaDeViagens[index] = runner;
						elementos++;
					}
					runner = Sucessor(runner);
				}while(runner != NULL);
			}
		}
		
		if(index == -1){
			return NULL;
		}
		return ListaDeViagens;
	
	}
	return NULL;
}
Viagem *filtrar_viagens_amigos_por_destino_u(Usuario *usuario, char *cidade, char *pais){
	if(usuario != NULL && cidade != NULL && pais != NULL && usuario->primeiro>-1 && strlen(cidade)<61 && strlen(pais)<31){
		int numeroViagens = 0;
		int dia,mes,ano,periodo,id;
		char cidade2[61],pais2[31];
		/*Conta quantas viagens os amigos tem naquele destino e salva o valor em numeroViagens*/
		for(int i = usuario->primeiro; i<=usuario->ultimo; i++){
			Usuario* amigo = usuario->amigos[i];
			if(usuario->primeiro>-1){
				Viagem* runner = Minimo(amigo->viagens);
				acessa_v(runner,&dia,&mes,&ano,cidade2,pais2,&periodo,&id);
				while(runner != NULL){
					if(strcmp(cidade,cidade2) == 0 && strcmp(pais,pais2) == 0){
						numeroViagens++;
					}
					runner = Sucessor(runner);
					acessa_v(runner,&dia,&mes,&ano,cidade2,pais2,&periodo,&id);
				}
			}
		}
		if(numeroViagens == 0){
			return NULL;
		}
		int pos = 0;
		Viagem** ListaDeViagens = (Viagem**) malloc(numeroViagens*tamanho_v());
		for(int i = usuario->primeiro; i<=usuario->ultimo; i++){
			Usuario* amigo = usuario->amigos[i];
			if(usuario->primeiro>-1){
				Viagem* runner = Minimo(amigo->viagens);
				acessa_v(runner,&dia,&mes,&ano,cidade2,pais2,&periodo,&id);
				while(runner != NULL){
					if(strcmp(cidade,cidade2) == 0 && strcmp(pais,pais2) == 0){
						ListaDeViagens[pos]=runner;
						pos++;
					}
					runner = Sucessor(runner);
					acessa_v(runner,&dia,&mes,&ano,cidade2,pais2,&periodo,&id);
				}
			}
		}
		return ListaDeViagens;
	
	}
	return NULL;
}
Usuario *filtrar_amigos_por_data_viagem_u(Usuario *usuario, int dia, int mes, int ano){
	if(usuario!=NULL && dia<32 && dia>0 && mes<32 && mes>0 && ano>0 && usuario->primeiro>-1){
		int pos = -1;
		int elementos = 0;
		int dia2,mes2,ano2,periodo,id2;
		char cidade[61],pais[31];
		int stop;
		Usuario** ListaDeAmigosComEssaData = (Usuario**) malloc(1*tamanho_u());
		int j = 0;
		while(j<=usuario->ultimo){
			stop = 0;
			Usuario* amigo = usuario->amigos[j];
			Viagem* runner = Minimo(amigo->viagens);
			do{
				acessa_v(runner,&dia2,&mes2,&ano2,cidade,pais,&periodo,&id2);
				if(dia == dia2 && mes == mes2 && ano == ano2){
					if(pos != -1){
						ListaDeAmigosComEssaData = (Usuario**) realloc(ListaDeAmigosComEssaData,(elementos+1)*tamanho_u());
					}
					pos++;
					ListaDeAmigosComEssaData[pos] = amigo;
					elementos++;
					stop = 1;
				}
				runner = Sucessor(runner);
			}while(runner!=NULL && stop == 0);
			j++;
		}
		if(pos == -1){
			return NULL;
		}
		return ListaDeAmigosComEssaData;
	}
	return NULL;
} 

Usuario *filtrar_amigos_por_destino_viagem_u(Usuario *usuario, char *cidade, char *pais){
	if(usuario!=NULL && cidade !=NULL && pais != NULL && strlen(cidade)<61 && strlen(pais)<31 && usuario->primeiro>-1){
		int pos = -1;
		int elementos = 0;
		int dia2,mes2,ano2,periodo,id2;
		int stop;
		char cidade2[61],pais2[31];
		Usuario** ListaDeAmigosComEsseDestino = (Usuario**) malloc(1*tamanho_u());
		int j = usuario->primeiro;
		while(j<=usuario->ultimo){
			stop = 0;
			Usuario* amigo = usuario->amigos[j];
			Viagem* runner = Minimo(amigo->viagens);
			do{
				acessa_v(runner,&dia2,&mes2,&ano2,cidade2,pais2,&periodo,&id2);
				if(strcmp(cidade,cidade2) == 0 && strcmp(pais,pais2) == 0){
					if(pos != -1){
						ListaDeAmigosComEsseDestino = (Usuario**) realloc(ListaDeAmigosComEsseDestino,(elementos+1)*tamanho_u());
					}
					pos++;
					ListaDeAmigosComEsseDestino[pos] = amigo;
					elementos++;
					stop = 1;
				}
				runner = Sucessor(runner);
			}while(runner!=NULL && stop == 0);
			j++;
		}
		if(pos == -1){
			return NULL;
		}
		return ListaDeAmigosComEsseDestino;
	}
	return NULL;

} 

int tamanho_u(){
	return sizeof(Usuario);
}