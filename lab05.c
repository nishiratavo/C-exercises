#include <stdio.h>

int main(){
	int N, M, i, i1;
	float v1, v2, v3;
	
	scanf(" %d", &N);
	
	for(i = 1; i <= N; i += 1){
		v2 = 0;
		scanf(" %d", &M);
		for(i1 = 1; i1 <= M; i1 += 1){
			scanf(" %f", &v1);
			v2 += v1;
			}
		v3 += v2;
		printf("Venda %d - Total: R$ %.2f.\n", i, v2);
		}
	
	printf("* Saldo do dia: R$ %.2f.\n", v3);

	
	return 0;
	}