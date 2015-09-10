// Gustavo Nishihara RA:169387

#include <stdio.h>

int primo(int n){
int m;
for(m = 2; m < n; m++){
	if(n%m == 0){
		return 0;
		break;
		}
	}
	return 1;
}

int main(void){

	int a1, a2, b1, b2, c1, c2, d1, d2, s1, s2, i, n, s, t;
	short int passou1, passou2;
	s1 = 0;
	s2 = 0;
	t = 0;
	s = 0;

	for(i = 1; s1 < 50 && s2 < 50; i+= 1)
	{
		s = 0;
		t = 0;
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
		
		if(primo(c1 -c2) == 1){
			s1 = s1 + 5;
			passou1 = 1;
		}
		
		
		if(primo(d1 - d2) == 1){
			s2 = s2 + 5;
			passou2 = 1;
			}
			

		for(n = c2 ; n <= c1; n+= 1){
			if(primo(n) == 1){
				s = s + n;
			}
		}
		
		if(s >= 1000){
					s1 = s1 + 2;
					passou1 = 1;
				}
		
		
		for(n = d2; n <= d1; n+= 1){
			if(primo(n) == 1){
				t = t + n;
			}
		}
		
		if(t >= 1000){
					s2 = s2 + 2;
					passou2 = 1;
				}
		
		if(passou1 == 0){
			s1 += 1;
			}
			
		if(passou2 == 0){
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
		
			
			
		
	
	