#include <stdio.h>
#include <math.h>
int main()
{
	double raio,vol;
	printf("Insira o valor do raio:");
	scanf("%lg",&raio);
	vol=(4.0/3)*3.14*pow(raio,3);
	printf("%lg\n", vol);
	return 1;
}