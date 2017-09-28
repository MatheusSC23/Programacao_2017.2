#include <stdio.h>
#define ordema 5
#define ordemb 8
int pertence(int k,int a[], int ordem)
{
    int existe = 0;
    int i=0;
    while(existe==0 && i<ordem)
    {
    	if(a[i]==k)
    	{
    		existe=1;
    	}
    	i++;
    }
    return existe;
}
int main(){
    int a[ordema]={2,5,1,4,3};
    int b[ordemb]={2,2,2,4,5,6,7,8};
    int igual[ordema],k;
    k=0;
    for(int i=0; i<ordema;i++)
    {
    	for(int j=0; j<ordemb;j++)
    	{
    		if(a[i]==b[j] && pertence(a[i],igual,ordema)==0)
    		{
    			igual[k]=a[i];
    			k++;
    		}
    	}
    }
    
    for(int i=0; i<k;i++)
    {
        printf("%d\n", igual[i]);
    }
    return 0;
}