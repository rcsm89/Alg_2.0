#include <iostream>
#include <algorithm>

using namespace std;

int get_len_lcs(string & s1, string & s2){

	int len_s1 = s1.size();
	int len_s2 = s2.size();

	int mat[len_s1+1][len_s2+1];

	for(int i = 1; i <= len_s1; i++)
			mat[i][0] = 0; //preenche primeira coluna com zero
	for(int i = 0; i <= len_s2; i++)
			mat[0][i] = 0; //preenche primeira linha com zero
	for(int i = 1;i <= len_s1; i++){
		for(int j = 1;j <= len_s2; j++){
			if(s1[i-1] == s2[j-1])
				mat[i][j] = mat[i-1][j-1] + 1;//pega o cara da diagonal soma com um e guarda
			else
				mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
		}
	}

	return mat[len_s1][len_s2];
}


int main() {
	string s1("bcacbcabbaccbab");
	string s2("bccabccbbabacbc");

	cout << "Lenght: " << get_len_lcs(s1, s2) <<  endl;
	return 0;
}
