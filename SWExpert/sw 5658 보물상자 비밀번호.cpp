#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <deque>

using namespace std;

int res = 0;
int n, k;
string a;

bool cmp(string a, string b) {
	return a > b;
}

int main() {
	int test; cin >> test;
	for (int t = 1; t <= test; t++) {
		deque <char> dq;
		vector <string> v;
		cin >> n >> k;
		string s; cin >> s;
		for (int i = 0; i < n; i++) {
			dq.push_back(s[i]);
		}
		int l = n / 4;
		for (int d = 0; d < l; d++) {
			for (int i = 1; i <= n; i++) {

				a += dq[i - 1];
				if (i % l == 0) {
					v.push_back(a);
					a = "";
				}
			}
			dq.push_front(dq.back());
			dq.pop_back();
		}
		sort(v.begin(), v.end(), cmp);
		v.erase(unique(v.begin(), v.end() - 1));
		res = stoi(v[k-1], nullptr, 16);
		cout << "#" << t << ' ' << res << '\n';

		//int x = stoi(a, nullptr, 16);
	}
}