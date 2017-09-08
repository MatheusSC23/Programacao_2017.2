#include<stdio.h>

int main(){
	double rad,graus,minutos,segundos;
	printf("Insira o angulo em radianos: ");
	scanf("%lg",&rad);
	graus=rad*57.2957;
	minutos= 60*(graus-(int)graus);
	segundos= 60*(minutos-(int)minutos);
	printf("São %d graus %d minutos e %d segundos.\n",(int) graus,(int) minutos,(int) segundos);
	return 1;
}