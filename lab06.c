#include <stdio.h>

int crivo(int n){
	int valor[10000];
	int i, j;
	for(i = 2; i <= 10000; i++){
		valor[i] = 1;
		for (j = i*i; j <= 10000;j += i){
			valor[j] = 0;
			}
		}
	if(valor[n] == 1){
		return 1;
		}
	return 0;
	}

int main(void){

	int a1, a2, b1, b2, c1, c2, d1, d2, s1, s2, i, n, s, t;
	short int passou1, passou2;
	s1 = 0;
	s2 = 0;
	t = 0;
	s = 0;

	for(i = 1; s1 < 50 || s2 < 50; i+= 1)
	{
		passou1 = 0;
		passou2 = 0;	
		scanf(" %d", &a1);
		scanf(" %d", &a2);
		scanf(" %d", &b1);
		scanf(" %d", &b2);
		
		if(a1 > a2){
			c1 = a1;
			c2 = a2;
			}
		else{
			c1 = a2;
			c2 = a1;
			}
			
		if(b1 > b2){
			d1 = b1;
			d2 = b2;
			}
		else{
			d1 = b2;
			d2 = b1;
			}
		
		if(crivo(c1 -c2) == 1){
			s1 = s1 + 5;
			passou1 = 1;
		}
		
		printf("s1 = %d\n",s1);
		
		if(crivo(d1 - d2) == 1){
			s2 = s2 + 5;
			passou2 = 1;
			}
			
		printf("s2 = %d\n", s2);

		for(n = c2; n <= c1; n++){
			if(crivo(n) == 1){
				s = s + n;
			}
		}
		
		if(s >= 1000){
					s1 = s1 + 2;
					passou1 = 1;
				}
		
		
		for(n = d2; n <= d1; n++){
			if(crivo(n) == 1){
				t = t + n;
			}
		}
		
		if(t >= 1000){
					s2 = s2 + 2;
					passou2 = 1;
				}
		
		if(crivo(c1 -c2) == 0 && passou1 == 0){
			s1 += 1;
			}
			
		if(crivo(d1 -d2) == 0 && passou2 == 0){
			s2 += 1;
			}
			
		
		if(s1 >= 50 && s2 < s1){
			printf("Numero de turnos: %d\n", i);
			printf("Jogador 1: %d pontos\n", s1);
			printf("Jogador 2: %d pontos\n", s2);
			printf("* Vencedor: Jogador 1\n");
			}
		else if(s2 >= 50 && s1 < s2){
			printf("Numero de turnos: %d\n", i);
			printf("Jogador 1: %d pontos\n", s1);
			printf("Jogador 2: %d pontos\n", s2);
			printf("* Vencedor: Jogador 2\n");
			}
			else if(s1 == s2 && s1 >= 50){
				printf("Numero de turnos: %d\n", i);
				printf("Jogador 1: %d pontos\n", s1);
				printf("Jogador 2: %d pontos\n", s2);
				printf("* Jogo empatado\n");
			}
				
			
			
	}
	
	return 0;
}
		
			
			
		
	
	