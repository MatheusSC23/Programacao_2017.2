#include<stdio.h>

int main(){
	int valor,i;
	printf("Insira o valor a ser calculado: ");
	scanf("%d",&valor);
	int notas[7]={100,50,20,10,5,2,1};
	int cels[7]={0,0,0,0,0,0,0};
	i=0;
	while(i<7){
		cels[i]=(int)(valor/notas[i]);
		valor-=cels[i]*notas[i];
		if(cels[i]>0){
			printf("%d cédulas de %d,",cels[i],notas[i]);
		}
		i++;
	}
	printf("\n");
	return 1;
}
