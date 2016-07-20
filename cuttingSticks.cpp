/*
 * cuttingSticks.cpp
 *
 *  Created on: 19 Jul 2016
 *      Author: ricardo
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lcs_mat[102][102];

int main() {
	vector<int> T1, T2;
	int one, two, maxTower, aux, cont = 1;

	do {
		cin >> one >> two;
		if (!one && !two)
			break;

		T1.clear();
		for (int i = 0; i < one; i++) {
			cin >> aux;
			T1.push_back(aux);
		}

		T2.clear();
		for (int i = 0; i < two; i++) {
			cin >> aux;
			T2.push_back(aux);
		}

		maxTower = max(two, one);

		for (int i = 0; i < maxTower; i++)
			lcs_mat[0][i] = lcs_mat[i][0] = 0;

		int i, j;
		for (i = 1; i <= one; i++) { //lcs_algorithm
			for (j = 1; j <= two; j++) {
				if (T1[i - 1] == T2[j - 1])
					lcs_mat[i][j] = lcs_mat[i - 1][j - 1] + 1;
				else if (lcs_mat[i - 1][j] >= lcs_mat[i][j - 1])
					lcs_mat[i][j] = lcs_mat[i - 1][j];
				else
					lcs_mat[i][j] = lcs_mat[i][j - 1];
			}
		}
		cout << "Twin Towers #" << cont++ << "\nNumber of Tiles : "
				<< lcs_mat[i - 1][j - 1] << endl;
	} while (one && two);
	return 0;
}
