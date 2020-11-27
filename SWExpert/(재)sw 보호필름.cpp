#include <iostream>
using namespace std;

int map[14][21];
int check[14][21];
int d, w, k;

int main() {
	int test; cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> d >> w >> t;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
	}
	for (int j = 0; j < w; j++) {
		for (int i = 0; i < d; i++) {
			if (i == 0)
				check[i][j] = 1;

		}
	}
}