#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

vector <int> inv;
int food[21][21];
vector <int> A, B;
int cal() {
	int taste_A = 0, taste_B = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			int x = A[i]; int y = A[j];
			if (i == j)
				continue;
			else {
				taste_A += food[x][y];
			}
		}
	}
	for (int i = 0; i < B.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			int x = B[i]; int y = B[j];
			if (i == j)
				continue;
			else {
				taste_B += food[x][y];
			}
		}
	}
	return abs(taste_A - taste_B);
}

void inv_sort(int x) {
	for (int i = 1; i <= n; i++) {
		if (i > n / 2)
			inv.push_back(0);
		else
			inv.push_back(1);
	}
	sort(inv.begin(), inv.end());
}

int main() {
	int test; cin >> test;
	for (int t = 1; t <= test; t++) {
		int res = 654321;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> food[i][j];
			}
		}
		inv.clear();
		inv_sort(n);
		do
		{
			A.clear(); B.clear();
			for (int i = 0; i < inv.size(); i++) {
				if (inv[i] != 1)
					A.push_back(i+1);
				else {
					B.push_back(i+1);
				}

			}
			int k = cal();
			if (res > k) 
				res = k;
		} while (next_permutation(inv.begin(),inv.end()));

		cout << "#" << t << " " << res << '\n';
	}
}