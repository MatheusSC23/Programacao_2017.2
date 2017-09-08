#include <stdio.h>
#include <stdlib.h>
int main(){
	float a,b,c;
	printf("Insira a:\n");
	scanf("%f",&a);
	printf("Insira b:\n");
	scanf("%f",&b);
	printf("Insira c:\n");
	scanf("%f",&c);
	if((abs(b-c)<a<b+c) && (abs(a-c)<b<a+c) && (abs(a-b)<c<a+b) ){
		if(a==b && a==c ){
			printf("Equilátero\n");
		}
		else if(a==b && c!=a){
			printf("Isóceles\n");
		}
		else{
			printf("Escalane\n");
		}
	}
	else{

		printf("Não é um tirângulo.\n");
	}
	return 0;
}