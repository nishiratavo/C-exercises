// Gustavo Nishihara  RA:169387   Programa do capeta, foi muito dificil fazer isso daqui
// Ainda bem que meu curso n é ciencia da computacao ou eng comp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Word *Vetor = NULL;
int count = 0;
struct Word{
	char palavra[80];
	char palavrau[80];
	int ocorrencias;
	
};

int contarpalavras(char vetor[])
{
	int i = 0;
	int flag = 0;
	int range=0;
	
	for(i = 0;vetor[i] != '\0';i++)
	{
		range++;
		if(!flag && vetor[i] !=' ')
		{
			flag = 1;
			count++;
		}
		else if (flag && vetor[i] ==' ')
		{	
			flag = 0;
			
		}
	}
	
	Vetor = (struct Word*)malloc(count*sizeof(struct Word));
	return count;
	
}

char* removerpont(char vetor[]) {
        int i;
        int j;
        int tamanhot, tamanhoc;
        char* caracter = ".,:;!?()\"\'";
        tamanhot = strlen(vetor);
        tamanhoc = strlen(caracter); 
        for (i = 0; i < tamanhot; i++)
        {
                for (j = 0; j < tamanhoc; j++)
                {
                        if (vetor[i] == caracter[j])
                        {
                                vetor[i]=' ';  
                        }
          }           
        }
 
        return vetor; 
}

int busca(char palavra[])
{
	int i;
	for(i=0;i < count;i++)
	{
		if(strcmp(Vetor[i].palavra, palavra) == 0)
		{
			return i;
		}
	}
	return -1;
}

void ocorrencia(char vetor[]) {

	
int i = 0, j=0, k = 0, fim, x;
    char aux[80];           
    fim = strlen(vetor);

    while (i<fim && k < count)
    {
    	for (;vetor[i] == ' '; i++){ 

        }
        
        if (vetor[i] != ' ') 
        {
            j = 0;
            while (vetor[i] != ' ' && vetor[i] != '\0') 
            {
                aux[j] = vetor[i];
                j++;		
                i++;		
            }
            aux[j] = '\0'; 

        }
			x = busca(aux);
			if(x > -1)
			{
				Vetor[x].ocorrencias++;
			}
			else
			{
				strcpy(Vetor[k].palavra, aux);
				Vetor[k].ocorrencias = 1;
			}
			k++;
			
		}
	}






void ordena(struct Word vet[], int n)
{
	int i, j;
	struct Word aux;
	
	for(i = 0;i<n;i++)
	{
		aux = vet[i];
		for(j = i; (j > 0)&&(aux.ocorrencias>vet[j-1].ocorrencias);j--)
		{
			vet[j] = vet[j-1];
		}
		vet[j] = aux;
	}
	
}
	
	



int main(){

char entrada[1000];
int i;
int count1=0;
int a;

fgets(entrada,1000,stdin);
a = strlen(entrada);
entrada[a-1] = '.';
contarpalavras(removerpont(entrada));
ocorrencia(entrada);
ordena(Vetor, count);

for(i = 0;i < count;i++)
	{
		printf("\"%s\", %d\n", Vetor[i].palavra, Vetor[i].ocorrencias);
		count1 += Vetor[i].ocorrencias;
		if(count1 == count)
		{
		return 0;
		}
	}
	



return 0;
}
