#include <stdio.h>
#include <stdlib.h>
int Buscar(int num, int* v)
{
	return sizeof(v);
}


int main()
{
	int n;
	printf("Insira o valor de n: \n");
	scanf("%d",&n);
	int* v = (int*) malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		printf("Insira o elemendo %d: ",i+1);
		scanf("%d",&v[i]);
	}
	free(v);
	printf("%d\n", Buscar(1,v));
	return 0;
}