#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,e,verificador,tail;
	printf("Insira o valor de n: \n");
	scanf("%d",&n);
	tail=0;
	int* v = (int*) malloc(n*sizeof(int));
	do
	{
		for(int i=0+tail;i<n;i++)
		{
			printf("Insira o elemendo %d: ",i+1);
			scanf("%d",&v[i]);
		}
		printf("Você deseja adicionar mais elementos? Digite 1 para sime 0 para não.\n");
		scanf("%d",&e);
		if(e==1)
		{
			tail=n;
			printf("Insira o valor de n: \n");
			scanf("%d",&verificador);
			if(verificador>n)
			{
				n=verificador;
				v=(int*) realloc(v,n*sizeof(int));
			}
		}
	}
	while(e!=0);
	for(int i=0;i<n;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
	free(v);
	return 0;
}