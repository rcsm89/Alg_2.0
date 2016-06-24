#include <cstdio>
#include <iostream>

using namespace std;

int vet[3] = {1, 2, 3};
int len = sizeof(vet)/sizeof(int);

void imprime(){
	for(int i = 0; i < len; i++)
		cout << vet[i] << " ";
	cout << endl;
}

void troca(int x, int y){
	int aux = vet[x];
	vet[x] = vet[y];
	vet[y] = aux;
}

void permutaRecursivo(int k){
	if(k == len){
		imprime();
	} else {
		for(int i = k; i < len; i++){
			troca(k, i);
			permutaRecursivo(k + 1);
			troca(i, k);
		}
	}
}

int main(){
	permutaRecursivo(0);
	return 0;
}
