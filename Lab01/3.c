#include<stdio.h>

int main(){
	float segundos;
	int hora,minuto;
	printf("Insira o tempo em segundos: ");
	scanf("%f",&segundos);
	hora=segundos/3600;
	segundos-=hora*3600;
	minuto=segundos/60;
	segundos-=minuto*60;
	printf("O tempo foi de %02d:%02d:%05.2f",hora,minuto,segundos);

	return 1;
}