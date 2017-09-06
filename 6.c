#include<stdio.h>

int main(){
	
	int ordem[3];
	printf("Insira o primeiro valor:");
	scanf("%d",&ordem[0]);
	printf("Insira o segundo valor:");
	scanf("%d",&ordem[1]);
	printf("Insira o terveiro valor:");
	scanf("%d",&ordem[2]);

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(ordem[i]<ordem[j]){
				int temp=ordem[i];
				ordem[i]=ordem[j];
				ordem[j]=temp;
			}
		}
	}

	printf("O maior número recebido foi %d\nNúmeros em ordem crescente:\n",ordem[2]);
	for(int i=0; i<3; i++){
		printf("%d\n",ordem[i]);
	}	

	return 1;
}
