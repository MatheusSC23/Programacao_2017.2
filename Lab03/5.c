#include <stdio.h>
#include <stdlib.h>
int* soma(int seq1[], int seq2[], int n)
{
	int* seq = (int*) malloc(n+1*sizeof(int));
	int resto=0;
	for(int i=n;i>0;i--)
	{
		seq[i]=(seq1[i-1]+seq2[i-1])%10+resto;
		resto=(int)(seq1[i-1]+seq2[i-1])/10;
	}
	seq[0]=resto;
	return seq;
}
int main()
{
	int n;
	printf("Insira n ");
	scanf("%d",&n);
	int* seq;
	int* seq1=(int*) malloc(n*sizeof(int));
	int* seq2=(int*) malloc(n*sizeof(int));
	printf("seq1\n");
	for(int i=0; i<n; i++)
	{
		printf("Insira o elemento %d de seq1 ",i+1);
		scanf("%d",&seq1[i]);
	}
	printf("seq2\n");
	for(int i=0; i<n; i++)
	{
		printf("Insira o elemento %d de seq2 ",i+1);
		scanf("%d",&seq2[i]);
	}
	for(int i=0; i<n; i++)
	{
		printf("%d",seq1[i]);
	}
	printf("\n");
	for(int i=0; i<n; i++)
	{
		printf("%d",seq2[i]);
	}
	seq=soma(seq1, seq2,n);
	printf("\n");
	for(int i=0; i<n+1; i++)
	{
		printf("%d",seq[i]);
	}
}
