//Gustavo Nishihara  RA:169387
//Programa muito chato que demorou mto tempo pra fazer tem struct, bubblesort e busca binaria

#include <stdio.h>
#include <string.h>


struct placataxi
	{
		int  numerop;
		char letrap[8];
	};

void bubbleSortNumero(struct placataxi  vet[], int tam){
  int i,j,aux_num;
	char aux_placa[7];

  for (i = tam-1; i > 0; i--){
  	for (j = 0; j < i; j++){
  		if ( vet[j].numerop > vet[j+1].numerop ){
				aux_num = vet[j].numerop;
				vet[j].numerop = vet[j+1].numerop;
				vet[j+1].numerop = aux_num;

				strcpy(aux_placa,vet[j].letrap);
				strcpy(vet[j].letrap,vet[j+1].letrap);
				strcpy(vet[j+1].letrap,aux_placa);
			}
		}
	}
}
	
void bubbleSortPlaca(struct placataxi vet[], int tam){
  int i,j,aux_num;
  char aux[8];
  for (i = tam-1; i > 0; i--){
  	for(j = 0; j < i; j++){
  		if (strcmp(vet[j].letrap,vet[j+1].letrap) > 0 ){
  				aux_num = vet[j].numerop;
				vet[j].numerop = vet[j+1].numerop;
				vet[j+1].numerop = aux_num;
  				
				strcpy(aux,vet[j].letrap);
				strcpy(vet[j].letrap,vet[j+1].letrap);
				strcpy(vet[j+1].letrap,aux);
			}
		}
	}
}

int buscaBinariaNumero(struct placataxi vet[], int tam, int chave){
  int posIni=0, posFim=tam-1, posMeio, a, b;
  while(posIni <= posFim){
  	posMeio = (posIni+posFim)/2;
    if(vet[posMeio].numerop == chave)
      return posMeio;
    else if(vet[posMeio].numerop > chave)
      posFim = posMeio - 1;
    else
      posIni = posMeio + 1;
  }

	
	
	if((vet[posFim].numerop - chave) < 0)
	{
		a = (vet[posFim].numerop - chave)*-1;
	}
	else
	{
		a = (vet[posFim].numerop - chave);
	}
	if((vet[posIni].numerop - chave) < 0)
	{
		b = (vet[posIni].numerop - chave)*-1;
	}
	else
	{
		b = (vet[posIni].numerop - chave);
	}
	if(a > b)
	{
		if (posIni > tam -1) posIni = tam-1;
		return posIni;
	}
	else 
	{
		return posFim;	
	} 
	
}

int buscaBinariap(struct placataxi vet[], int tam, char chave[]){
  int posIni=0, posFim=tam-1, posMeio;
  while(posIni <= posFim){
  	posMeio = (posIni+posFim)/2;
    if(strcmp(vet[posMeio].letrap,chave) == 0)
      return posMeio;
    else if(strcmp(vet[posMeio].letrap,chave) > 0)
      posFim = posMeio - 1;
    else
      posIni = posMeio + 1;
	}
	return -1;
	}

int main() {
	int N,i,j,M;
	char selecao;
	char S[8];
		
	scanf(" %d", &N);
	struct placataxi placa[N];
	struct placataxi numero[N];
	for(i = 0;i < N;i++)
	{
		scanf(" %s", placa[i].letrap);
		for(j = 0;j < 7;j++){
			numero[i].letrap[j] = placa[i].letrap[j];
		}
		numero[i].letrap[7]='\0';
		scanf(" %d", &placa[i].numerop);
		numero[i].numerop = placa[i].numerop;
	}
	
	bubbleSortNumero(numero, N);
	bubbleSortPlaca(placa, N);
	
	for(i = 0; i < N; i++){
		printf("%s\n",numero[i].letrap);
		}
	for(i = 0; i < N;i++)
	{
		printf("%s\n", placa[i].letrap);
	}
	
	
	scanf(" %s", &selecao);
	while(selecao != 'S')
	{
	if(selecao == 'K')
	{
		scanf(" %d", &M);
		printf("%s\n", numero[buscaBinariaNumero(numero, N, M)].letrap);
	}
	else if(selecao == 'P')
	{
		scanf(" %s", S);
		printf("%d\n", placa[buscaBinariap(placa, N, S)].numerop);	
	}
	scanf(" %s", &selecao);
	}
	
return 0;
}
