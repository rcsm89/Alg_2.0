#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int get_ds(string & s1, string & s2) {

	int len_s1 = s1.size();
	int len_s2 = s2.size();

	int mat[len_s1 + 1][len_s2 + 1];

	for (int i = 0; i <= len_s2; i++)
		mat[0][i] = 0; //preenche primeira linha com zero
	for (int i = 0; i <= len_s1; i++)
		mat[i][0] = 1; //preenche primeira coluna com um

	for (int i = 1; i <= len_s1; i++) {
		for (int j = 1; j <= len_s2; j++) {
			if (s1[i - 1] == s2[j - 1])
				mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
			else
				mat[i][j] = mat[i - 1][j];
		}
	}

	return mat[len_s1][len_s2];
}

int main() {
	int N;
	string X;
	string Z;
	
	scanf("%d", &N);

	while(N--){
		getline(cin, X);
		if(X == "") getline(cin, X);
		getline(cin, Z);
		cout << get_ds(X, Z);
	}

	return 0;
}