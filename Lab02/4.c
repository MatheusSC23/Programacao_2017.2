#include <stdio.h>

double volume(float r){
	return (4.0/3)*3.14*r*r*r;
}
double area(float r){
	return 4*3.14*r*r;
}
int main(){
	int i;
	float r;
	while(i!=2)
	{
		printf("Dirige 0 para o volume e 1 para a área 2 para sair:\n");
		scanf("%d", &i);
		if(i==0)
		{
			printf("Insira o raio: \n");
			scanf("%f",&r);
			printf("O volume é %lg\n", volume(r));
		}
		else if(i==1)
		{
			printf("Insira o raio: \n");
			scanf("%f",&r);
			printf("A área é %lg\n", area(r));
		}
	}
	return 0;
}