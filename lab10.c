// Gustavo Nishihara RA:169387
//Simples programa para calcular rendimento com funções e recursão para juros compostos
#include <stdio.h>

float juros(float m,int t, float j, float apm)
{
	int i = 0;
	float s = m;
	for(i = 1; i <= t; i++)
	{
		s += apm+ s*j;
	}
	return s;
}

float rent_banco1(float investimento, int tempo)
{
	float j = 0.008;
	float jp = 0.004; 
	float apm = 500.0;
	if(tempo >= 18)
	{
		return juros(investimento,tempo,j,apm)-(investimento + 500*tempo);
	}
	else if(tempo < 18)
	{
		return juros(investimento,tempo,jp,apm)-(investimento + 500*tempo);
	}
	return 0;
}

float rent_banco2(float investimento, int tempo)
{
	float j = 0.006; 
	float apm = 500;
	return juros(investimento,tempo,j,apm)-(investimento + 500*tempo);
}

float rent_banco3(float investimento, int tempo)
{
	float j = 0.0115;
	float jp = 0.0; 
	float apm = 500;
	if(tempo >= 24)
	{
		return juros(investimento,tempo,j,apm)-(investimento + 500*tempo);
	}
	else if(tempo < 24)
	{
		return juros(investimento,tempo,jp,apm)-(investimento + 500*tempo);
	}
	return 0;
}

int main()
{
float s = 0.0;
float m;
int b1 = 0;
int b2 = 0;
int b3 = 0;
int N, i, t, sf;

scanf(" %d", &N);

for(i = 1; i <= N; i++)
{
	scanf(" %f", &m);
	scanf(" %d", &t);
	if(rent_banco1(m,t) > rent_banco2(m,t) && rent_banco1(m,t) > rent_banco3(m,t))
	{
		b1 += 1;
		s += rent_banco1(m,t);
	}
	else if(rent_banco2(m,t) > rent_banco1(m,t) && rent_banco2(m,t) > rent_banco3(m,t))
	{
		b2 += 1;
		s += rent_banco2(m,t);
	}
	else if(rent_banco3(m,t) > rent_banco1(m,t) && rent_banco3(m,t) > rent_banco2(m,t))
	{
		b3 += 1;
		s += rent_banco3(m,t);
	}

}
printf("%d\n",sf = s);
printf("%d\n",b1);
printf("%d\n",b2);
printf("%d\n",b3);

return 0;
}