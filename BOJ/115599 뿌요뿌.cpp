#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

char map[13][7];
int visited[13][7];
queue<pair<int, int>> pq;
queue<pair<int, int>> q;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Down_ppuyo() {
	for (int i = 0; i < 6; i++) {
		int nx = 11;
		int em = 0;
		while (nx > 0) {
			if (map[nx][i] == '.') {
				nx--;
				em++;
			}
			else {
				if (nx == 11)
					break;
				else {
					map[nx + em][i] = map[nx][i];
					map[nx][i] = '.';
					nx--;
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
				if (map[x][y] == map[nx][ny] && visited[nx][ny] == 0) {
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
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	while (1) {
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && visited[i][j] == 0)
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

		if (flag) {
			result++;
			Down_ppuyo();

		}
		else
			break;
	}
	cout << result;
}