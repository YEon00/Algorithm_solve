#include <iostream>
#include <queue>
using namespace std;

char map[13][7];
int visited[13][7];
queue<pair<int, int>> pq;
queue<pair<int, int>> q;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Down_ppuyo() {
	for (int i = 0; i < 6; i++) {
		int nx = 12;
		int em = 0;
		int temp = 0;
		bool flag = false;
		while (nx--) {
			if (map[nx][i] == '.') {
				if (!flag) {
					temp = nx;
					flag = true;
				}
				em++;
			}
			else {
				if (temp != 0) {
					map[temp][i] = map[temp - em][i];
					map[temp - em][i] = '.';
					temp--;
				}
			}
		}
	}
}


void POP_check(int x, int y) {
	int check = 1;
	visited[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second;
		pq.push({ x,y });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 12 && ny < 6) {
				if (map[x][y] == map[nx][ny] && visited[nx][ny]==0) {
					q.push({ nx,ny });
					visited[nx][ny] = 1;
					check++;
				}
			}
		}
	}
	if (check >= 4) {
		while (!pq.empty()) {
			visited[pq.front().first][pq.front().second] = 2;
			pq.pop();
		}
	}
	else {
		while (!pq.empty())
			pq.pop();
	}

}

int main() {
	int result = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j <6; j++) {
			cin >> map[i][j];
		}
	}
	while (1) {
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && visited[i][j]==0)
					POP_check(i, j);
			}
		}
		bool flag = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (visited[i][j] == 2) {
					map[i][j] = '.';
					flag = true;
				}
			}
		}
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}
		if (flag) {
			result++;
			Down_ppuyo();
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					cout << map[i][j];
				}
				cout << '\n';
			}
		}
		else
			break;
	}
	cout << result;
}
