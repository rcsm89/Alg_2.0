#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int estaCheio (int vet, int tam) {
	int i;

	for(i=1; i<=tam; i++){
		if(vet[i] == 0)
			return false;
	}
	return true;
}

int estaPresente(int *vet, int index, int newElm){
	int i;

	for(i=index; i>=1; i--){
		if(vet[i] == newElm){
			return false;
		}
	}
	return true;
}

void permutaN(int *vet, int t){
	int vetSolve[t];

	
}



int main(){

	int vet[10];
	int permutacoes[10];
	int nP = 0;
	int i, t;

	scanf("%d", &t);
	for(i=1; i<=t; i++){
		vet[i] = i;
	}

	permutaN(vet, nP);

	return 0;
}