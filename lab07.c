//Gustavo Nishihara RA:169387
// simples programa que utiliza uma função para converter char para int e  encontrar números primos
// com um for é possível ler as entradas e calcular o que é pedido
#include <stdio.h>

	int primalidade(char v)
	{
		int n = v;
		int i;
		int a;
		for(i = 2; i< n; i++)
		{
			if(n%i == 0)
			{
				a = 0;
				break;
			}
			else{
				a = 1;
				}
		}
		return a;
	}
				
int main(int argc, char* argv[]){
	int N, a;
	char c;
	int p = 0;
	int t;
	int composto = 0;
	scanf( "%d", &N);
	
	for(a = 1;a <= N; a++)
	{
		scanf(" %c", &c);
		if(primalidade(c) == 1)
		{
			p ++;
		}
		else
		{
			composto ++;
		}
		t = c;
		
	}
	
	printf("A palavra possui %d caracteres primos.\n", p);
	printf("A palavra possui %d caracteres compostos.\n", composto);
		
	return 0;
	}