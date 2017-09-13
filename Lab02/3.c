#include <stdio.h>

int mdc(int x, int y){
	int r = x%y;
	if (r==0){
		return y;
	}
	else{
		return mdc(y,r);
	}
}
int main(){
	int escolha=0;
	while(escolha!=2){
		int x,y,z;
		printf("Digite 1 para calcular o mdc e 2 para sair: ");
		scanf("%d",&escolha);
		if(escolha==1){
			printf("Insira o primeiro valor: ");
			scanf("%d",&x);
			printf("Insira o segundo valor: ");
			scanf("%d",&y);
			printf("Insira o terceiro valor: ");
			scanf("%d",&z);
			printf("O mdc é %d\n", mdc(mdc(x,y),z));
		}
	}
}