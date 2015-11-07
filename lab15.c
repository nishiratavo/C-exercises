//Gustavo Nishihara RA:169387  
//pegaram mais leve nesse daqui né

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
char teste[100]; //vai armazenar a primeira linha
int n[2];        //vai armazenar o tamanho da matriz
int nf[2];       //vai armazenar o tamanho do filtro
int i,j,max,a;   //max armazena o 255
FILE *arq1;
FILE *arq2;
arq1 = fopen(argv[1], "r");
arq2 = fopen(argv[2], "r");
fscanf(arq1, "%s", teste);//armazena primeira linha
for(i = 0;i < 2;i++)//armazena segunda linha
{
	fscanf(arq1,"%d", &n[i]);
}

fscanf(arq1, "%d", &max);//armazena terceira linha

int matriz[n[1]+2][n[0]+2];//definido tamanho da matriz inicial com uma margem em volta dela
int matrizf[n[1]][n[0]];//definido tamanho da matriz final

for(i = 0;i < n[0]+2;i++)//criando linhas de 0 na margem
{
	matriz[0][i] = 0;
	matriz[n[1]+1][i] = 0;
}

for(i = 1;i < n[1]+1;i++)//criando colunas de 0 na margem
{
	matriz[i][0] = 0;
	matriz[i][n[0]+1] = 0;
}
	
for(i = 1;i <= n[1];i++)//armazenando os valores da matriz na matriz inicial
{
	for(j = 1;j <= n[0];j++)
	{
		fscanf(arq1, "%d ", &matriz[i][j]);
	}
}



for(i = 0;i < 2;i++)//armazenando valores do tamanho do filtro
{
	fscanf(arq2,"%d ", &nf[i]);
}

int filtro[3][3];

if(nf[0] == 3 && nf[1] == 1)//centralizando o filtro para tamanho diferente de 3x3
{
	for(i=1;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			fscanf(arq2, "%d ", &filtro[i][j]);
		}
	}
	
	for(i=0;i<1;i++)
	{
		for(j=0;j<3;j++)
		{
			filtro[i][j] = 0;
		}
	}
	
	for(i=2;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			filtro[i][j] = 0;
		}
	}
}
else// armazenando filtro 3x3
{
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
		{
			fscanf(arq2, "%d ", &filtro[i][j]);
		}
	}
}


for(i = 1;i < n[1]+1;i++)//aplicacao do filtro sobre a matriz inicial
	{
		for(j = 1; j < n[0]+1;j++)
		{
			a = (filtro[0][0]*(matriz[i - 1][j - 1])) + (filtro[0][1]*(matriz[i -1][j])) + (filtro[0][2]*(matriz[i-1][j+1])) + (filtro[1][0]*(matriz[i][j-1])) + (filtro[1][1]*(matriz[i][j])) + (filtro[1][2]*(matriz[i][j+1])) + (filtro[2][0]*(matriz[i+1][j-1])) + (filtro[2][1]*(matriz[i+1][j])) + (filtro[2][2]*(matriz[i+1][j+1]));
			matrizf[i-1][j-1] = a;
		}
	}
	
for(i = 0;i < n[1];i++)//truncando valores da matriz final para intervalo [0,255]
	{
		for(j = 0; j < n[0];j++)
		{
			if(matrizf[i][j] <= 0)
			{
				matrizf[i][j] = 0;
			}
			else if(matrizf[i][j] >= 255)
			{
				matrizf[i][j] = 255;
			}
		}
	}
//print dos dados para o resultado.pgm
printf("%s\n", teste);
printf("%d ", n[0]);
printf("%d\n", n[1]);
printf("%d\n", max);
for(i=0;i < n[1];i++)
{
	for(j=0;j < n[0]-1;j++)
	{
		printf("%d ", matrizf[i][j]);
	}
	printf("%d \n", matrizf[i][j]);
}


fclose(arq1);
fclose(arq2);
return 0;
}