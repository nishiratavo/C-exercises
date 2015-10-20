//Gustavo Nishihara RA: 169387 
//Simples programa para calcular distancia em vetores

#include <stdio.h>
#include <math.h>

int x, y;

float distancia(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
}

void bubbleSortx(int vetx[], int vety[], int tam){
   int i,j, aux;
    for(i=tam-1; i>0; i--){
		for(j=0;j<i;j++){
			if( distancia(vetx[j],vety[j],x,y) > distancia(vetx[j+1],vety[j+1],x,y) ){
				aux = vetx[j];
				vetx[j] = vetx[j+1];
				vetx[j+1] = aux;
			}
		}
	}
}

void bubbleSort(int vetx[], int vety[], float distanciav[], int tam){
   int i,j;
   float aux;
   int auxx, auxy;
    for(i=tam-1; i>0; i--){
		for(j=0;j<i;j++){
			if( distanciav[j]> distanciav[j+1] ){
				aux = distanciav[j];
				distanciav[j] = distanciav[j+1];
				distanciav[j+1] = aux;
				
				auxy = vety[j];
				vety[j] = vety[j+1];
				vety[j+1] = auxy;
				
				auxx = vetx[j];
				vetx[j] = vetx[j+1];
				vetx[j+1] = auxx;
			}
		}
	}
}

int main()
{
int N,i,K;
	
scanf(" %d", &N);
int vet[2*N];
int vetx[N];
int vety[N];
float distanciav[N];
for(i =0; i < 2*N;i++)
{
	scanf(" %d", &vet[i]);
}
for(i = 0;i < N;i++)
{
	vety[i] = vet[2*i + 1];
	vetx[i] = vet[2*i];
}


scanf(" %d", &K);
while(K >= 0){
scanf(" %d", &x);
scanf(" %d", &y);
for(i = 0;i < N;i++)
{
	distanciav[i] = distancia(vetx[i], vety[i], x, y);
}
bubbleSort(vetx, vety, distanciav, N);
for(i = 0; i < K;i++)
{
	printf("%d\n", vetx[i]);
	printf("%d\n", vety[i]);
}
scanf(" %d", &K);
}

return 0;
}
	