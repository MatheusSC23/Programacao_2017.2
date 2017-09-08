#include<stdio.h>
int main(){
	double s0,s,v0,v,a,t;
	printf("Insira o valor do S0:");
	scanf("%lg",&s0);
	printf("Insira o valor do V0:");
	scanf("%lg",&v0);
	printf("Insira o valor da aceleração:");
	scanf("%lg",&a);
	printf("Insira o valor do tempo:");
	scanf("%lg",&t);
	s=s0+v0+(a*t*t)/2;
	v=v0+a*t;
	printf("O s será:%lg\nO v será:%lg\n",s,v);
	return 1;
}