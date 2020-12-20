#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int build[501], entry[501];
int result[501];
vector <int> v[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> build[i];
		while (1) {
			int x; cin >> x;
			if (x == -1) break;
			v[x].push_back(i);
			entry[i]++;
		}
	}
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (entry[i] == 0) {
			q.push(i);
			result[i] = build[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			entry[next]--;

			result[next] = max(result[next], result[cur] + build[next]);
			if (entry[next] == 0)
				q.push(next);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}
	
	return 0;
}