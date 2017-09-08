#include<stdio.h>

int main(){
	float p1,p2,p3;
	float media;
	printf("Insira p1:");
	scanf("%f",&p1);
	printf("Insira p2:");
	scanf("%f",&p2);
	media=(p1+p2)/2;
	if(p1>=3 && p2>=3 && media>=5){
		printf("Aluno passou direto com média %.02f.\n",media);
	}
	else{
		printf("Insira p3:");
		scanf("%f",&p3);
		if(p1>p2){
			media = (p1+p3)/2;
		}
		else{
			media = (p2+p3)/2;
		}
		if(media>=5){
			printf("Você passou com média %.02f.\n",media);
		}
		else{
			printf("Você não passou. média: %.02f\n",media);
		}
	}
	return 1;
}
