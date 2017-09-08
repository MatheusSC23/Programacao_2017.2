#include<stdio.h>

int main()
{
	double preco,taxa; /*o  preço  do  galão  de  gasolina  praticado  nos  Estados  Unidos  (em  dólares)  e  a  taxa  de conversão  do  dólar  para  o  real*/
	printf("Insira o preço do galão de gasolina: ");
	scanf("%lg",&preco);
	printf("Insira a taxa de conversão: ");
	scanf("%lg",&taxa);
	preco = preco*(1/3.7854)*taxa;
	printf("O preço seria o de %lg por litro.\n ", preco);
	return 1;
}