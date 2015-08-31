// Gustavo Nishihara RA:169387
// para resolver esse problema só foi necessário usar dois loops para achar os divisores 
// e um if para comparar a soma dos divisores

#include <stdio.h>

int main() {

	int n1, n2, s1, s2;
	int n01 = 1;
	int n02 = 1;
	
	scanf(" %d\n", &n1);
	scanf(" %d", &n2);
	
	while(n01 <= n1 - 1){
		if(n1%n01 == 0){
			s1 = s1 + n01;
			n01 += 1;
			}
		else{
			n01 += 1;
			}
		}
	
	while(n02 <= n2 - 1){
		if(n2%n02 == 0){
			s2 = s2 + n02;
			n02 += 1;
			}
		else{
			n02 += 1;
			}
		}
	
	if(s1 == n2 && s2 == n1){
		printf("Os numeros sao amigos.\n");
		}
	else{
		printf("Os numeros nao sao amigos.\n");
		}
		
		
	return 0;
	}
	
		
		
		
	