#include <iostream>
#include <algorithm>

using namespace std;

int a[101][101];
int b[101][101];
int n, l, r;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int pre_person;
int compare_person;
pair <int, int> move_check(int x, int y, int cnt, int avg) {
	pre_person = a[x][y];
	if (b[x][y] == 0) {
		avg = a[x][y];
		cnt++;
	}
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < n && ny < n) {
			compare_person = a[nx][ny];
			int c = abs(pre_person - compare_person);
			if (c >= l && c <= r) {
				if (b[nx][ny] == 0) {
					b[nx][ny] = 1;
					cnt++;
					avg += compare_person;
				}
				b[x][y] = 1;
			}
		}
	}
	if (cnt == 0)
		avg = 0;
	if (b[x][y] == 0)
	{
		avg = 0; cnt = 0;
	}
	return make_pair(cnt, avg);
}
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int result = 0;
	while (1) {
		int person_cnt = 0;
		int avg = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				pair<int,int> q = move_check(i, j, 0,0);
				person_cnt += q.first;
				avg += q.second;
			}
		}
		if (avg == 0)
			break;
		avg = avg / person_cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (b[i][j] == 1) {
					a[i][j] = avg;
					b[i][j] = 0;
				}
				cout << a[i][j];
			}
			cout << '\n';
		}
		result++;
	}
	cout << result;

}