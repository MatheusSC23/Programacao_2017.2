typedef struct viagem Viagem; 
 
Viagem *nova_v(int dia, int mes, int ano, char *cidade, char *pais, int periodo); 
void libera_v(Viagem *viagem); 
void acessa_v(Viagem *viagem, int *dia, int *mes, int *ano, char *cidade, char *pais, int *periodo, int *id); 
void atribui_v(Viagem *viagem, int dia, int mes, int ano, char *cidade, char *pais, int periodo); 
void atribui_direita_v(Viagem *viagem, Viagem *direita); 
Viagem *acessa_direita_v(Viagem *viagem); 
void atribui_esquerda_v(Viagem *viagem, Viagem *esquerda); 
Viagem *acessa_esquerda_v(Viagem *viagem); 
void atribui_pai_v(Viagem *viagem, Viagem *pai);
Viagem *acessa_pai_v(Viagem *viagem);
Viagem *Minimo(Viagem* viagem);
Viagem *Sucessor(Viagem* viagem);
void Transplantar(Viagem* raiz, Viagem* viagem1, Viagem* viagem2);
void Remover(Viagem* raiz, Viagem* viagem);
int tamanho_v(); 