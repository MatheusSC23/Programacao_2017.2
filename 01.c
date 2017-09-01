#include <stdio.h>
#include <math.h>
int main()
{
	double raio,vol;/*Declaração das variáveis do raio e do volume*/
	printf("Insira o valor do raio:");
	scanf("%lg",&raio);
	vol=(4.0/3)*3.14*pow(raio,3);/*Cálculo do volume da esfera*/
	printf("%lg\n", vol);
	return 1;
}
