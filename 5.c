#include<stdio.h>

int main(){
	int valor,i;
	printf("Insira o valor a ser calculado: ");
	scanf("%d",&valor);
	int notas[7]={100,50,20,10,5,2,1};
	int cels[7]={0,0,0,0,0,0,0};
	int result=0;
	i=0;
	while(i<7){
		cels[i]=(int)(valor/notas[i]);
		printf("%d\n",cels[i] );
		valor-=cels[i]*notas[i];
		i++;
	}
	i=0;
	while(i<7){
		result+=cels[i]*notas[i];
		i++;
	}
	printf("%d\n",result);
	return 1;
}