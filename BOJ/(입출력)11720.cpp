#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int sum = 0;
	string s; cin >> s;
	for (int i = 0; i < n; i++) {
		sum += s[i] - '0';
	}
	cout << sum;
}