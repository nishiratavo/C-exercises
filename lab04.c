// Gustavo Nishihara RA: 169387
// para resolver esse problema só foi necessário adaptar o somatório para for

#include <stdio.h>

int main(){
	
	int i, n;
	float pi;
	float s;
	
	scanf(" %d", &n);
	for(i = 0;i <= n - 1; i += 1){
		if(i%2 == 0){
			s = 4.0/((2*i)+1);
			pi = pi + s;
			}
		else{	
			s = -4.0/((2*i)+1);
			pi = pi + s;
		}
	}
		
	printf("%.4f\n", pi);
		
	return 0;
	}
		
		
	