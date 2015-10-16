//Gustavo Nishihara RA:169387
//programa com várias funções, que demorou pra fazer 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float add(float *a, float *b, int N)
{
	int i;
	float c[N];
	for(i = 0; i < N; i++)
	{
		c[i] = a[i] + b[i];
	}
	printf("a+b = [");
	for(i = 0;i < N -1; i++)
	{
		printf("%.2f, ", c[i]);
	}
	printf("%.2f]\n", c[N -1]);
	return 0;
}

float produto_escalar(float *a, float *b, int N)
{
	int i;
	float produto = 0.0;
	for(i = 0;i < N;i++)
	{
		produto += a[i]*b[i];
	}
	printf("<a,b> = %.2f\n", produto);
	return 0;
}

float norma(float *a, float *b, int N)
{
	int i;
	float normaa = 0.0;
	float normab = 0.0;
	for(i = 0;i < N;i++)
	{
		normaa += a[i]*a[i];
	}
	for(i = 0;i < N;i++)
	{
		normab += b[i]*b[i];
	}
	normaa = sqrt(normaa);
	normab = sqrt(normab);
	printf("|a| = %.2f\n", normaa);
	printf("|b| = %.2f\n", normab);
	return 0;
}

float produto_diatico(float *a, float *b, int N)
{
	int ia, ib;
	float d[N][N];
	for(ia = 0;ia < N;ia++)
	{
		for(ib = 0;ib < N;ib++)
		{
			d[ia][ib] = a[ia]*b[ib];
		}
	}
	printf("a x b\n");
	for(ia = 0;ia < N;ia++)
	{
		printf("[");
		for(ib = 0;ib < N -1; ib++)
		{
			printf("%.2f, ", d[ia][ib]);
		}
		printf("%.2f]\n", d[ia][N -1]);
	}
	return 0;
}

float cosseno(float *a, float *b, int N)
{
	int i;
	float produto = 0.0;
	for(i = 0;i < N;i++)
	{
		produto += a[i]*b[i];
	}
	float normaa = 0.0;
	float normab = 0.0;
	for(i = 0;i < N;i++)
	{
		normaa += a[i]*a[i];
	}
	for(i = 0;i < N;i++)
	{
		normab += b[i]*b[i];
	}
	normaa = sqrt(normaa);
	normab = sqrt(normab);
	
	float cos = (produto)/(normaa*normab);
	printf("cos = %.2f\n", cos);
	return 0;
}

int main()
{
	int N, i;
	char entrada;
	scanf(" %d", &N);
	float a[N], b[N];
	for(i = 0;i < N;i++)
	{
		scanf(" %f", &a[i]);
	}
	for(i = 0;i < N;i++)
	{
		scanf(" %f", &b[i]);
	}
	printf("a = [");
	for(i = 0;i < N -1; i++)
	{
		printf("%.2f, ", a[i]);
	}
	printf("%.2f]\n", a[N -1]);
	
	printf("b = [");
	for(i = 0;i < N -1; i++)
	{
		printf("%.2f, ", b[i]);
	}
	printf("%.2f]\n", b[N -1]);
	while(1)
	{
		scanf(" %c", &entrada);
		if(entrada == 'q')
		{
			break;
		}
	
		switch(entrada)
		{
			case 'a':
				add(a,b,N);
				break;
			case 'p':
				produto_escalar(a,b,N);
				break;
			case 'n':
				norma(a,b,N);
				break;
			case 'd':
				produto_diatico(a,b,N);
				break;
			case 'c':
				cosseno(a,b,N);
				break;
		}
	}
	return 0;
}





























