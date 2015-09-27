//Gustavo Nishihara RA:169387
//Simples programa com tres funcoes, o qual calcula pontos a partir da velocidade e distancia do motoboy

#include <stdio.h>
#include <math.h>

float distancia(float localizacao1_x, float localizacao1_y, float localizacao2_x, float localizacao2_y)
{
	return sqrt(pow(localizacao1_x - localizacao2_x,2) + pow(localizacao1_y - localizacao2_y,2));
}

float converter_velocidade(float velocidade_kmh)
{
	return (velocidade_kmh*50)/3;
}

int pontos(float localizacao1_x, float localizacao1_y, float localizacao2_x, float localizacao2_y, float velocidade_kmh)
{
	if(distancia(localizacao1_x,localizacao1_y,localizacao2_x,localizacao2_y) >= 5000.0 || (distancia(localizacao1_x,localizacao1_y,localizacao2_x,localizacao2_y)/converter_velocidade(velocidade_kmh)) < 15.0)
		{
			return 5;
		}
	else
		{
			return 1;
		}

}

int main()
{
int s = 0;
float px,py,cx,cy,v;
int n,i;


scanf(" %f", &px);
scanf(" %f", &py);
scanf(" %d", &n);

for(i = 1; i <= n; i++)
{
	scanf(" %f", &cx);
	scanf(" %f", &cy);
	scanf(" %f", &v);
	s += pontos(px,py,cx,cy,v);
}

printf("%d\n",s);


return 0;
}