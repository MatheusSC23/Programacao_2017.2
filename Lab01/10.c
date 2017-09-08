#include <stdio.h>
#include <stdlib.h>
int main(){
	int p,i,m;
	while(p!=3){
		printf("Digite a sua escolha: \n0.Pedra\n1.Papel\n2.Tesoura\n3.Sair\n");
		scanf("%d",&p);
		m=rand() % 2;
		if(p==3){
			printf("Bye Bye Baby.;)");
		}
		if(m!=p){
			if((p==0 && m==1) || (p==1 && m==0) || (p==2 && m==1)){
				printf("Você venceu.\n");
			}
			else{
				printf("Você perdeu.\n");
			}
		}
		else{
			printf("Empate!\n");
		}
	}
	return 0;
}