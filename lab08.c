//Gustavo Nishihara RA:169387
//função para cos, sen, senh, cosh, e depois switch para selecionar valores
#include <stdio.h>

float fatorial(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n == 1)
	{
		return 1;
	}
	else
	{
		return n*fatorial(n-1);
	}
}

float pot(float b,int e)
{
	if(e == 0)
	{
		return 1;
	}
	else
	{
		return b*pot(b, e-1);
	}
}

float seno(int N, float x) 
{	
	float s = 0.0;
	int i = 0;
	for(i = 0; i <= N; i++)
	{
		s += (pot(-1,i)/fatorial(2*i + 1))*pot(x, 2*i + 1);
	}
	return s;
}

float cosseno(int N, float x) 
{	
	float s = 0.0;
	int i = 0;
	for(i = 0; i <= N; i++)
	{
		s += (pot(-1,i)/fatorial(2*i))*pot(x, 2*i);
	}
	return s;
}

float senh(int N, float x) 
{	
	float s = 0.0;
	int i = 0;
	for(i = 0; i <= N; i++)
	{
		s += (pot(x,2*i + 1)/fatorial(2*i+1));
	}
	return s;
}

float cossenoh(int N, float x) 
{	
	float s = 0.0;
	int i = 0;
	for(i = 0; i <= N; i++)
	{
		s += (1/fatorial(2*i))*pot(x, 2*i);
	}
	return s;
}




int main(){

	char l = 'a';
	float x, y;
	int N;

	while(1)
	{	
		scanf(" %c", &l);
		if(l == 'f' || l == 'F')
		{
			break;
		}
// switch pra escolher os baguio
		switch(l)
		{
			case 's':
				scanf("%f", &x);
				scanf("%d", &N);
				y = seno(N,x);//retornando valor de seno
				printf("O valor aproximado de seno de %.4f eh %.4f.\n", x, y);
				break;
			case 'c':
				scanf("%f", &x);
				scanf("%d", &N);
				y = cosseno(N,x);
				printf("O valor aproximado de cosseno de %.4f eh %.4f\n.", x, y);
				break;
			case 'S':
				scanf("%f", &x);
				scanf("%d", &N);
				y = senh(N,x);
				printf("O valor aproximado de seno hiperbolico de %.4f eh %.4f.\n", x, y);
				break;
			case 'C':
				scanf("%f", &x);
				scanf("%d", &N);
				y = cossenoh(N,x);
				printf("O valor aproximado de cosseno hiperbolico de %.4f eh %.4f.\n", x, y);
				break;
			default://caso nao seja caracter valido
				printf("Comando invalido.\n");
				break;//break pra sair do switch
		}
	}
	return 0;
}