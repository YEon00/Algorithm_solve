#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int r, c, s, d, z;
int res = 0;
int R, C, M;

int map[101][101];

int dx[] = { 0,0,0,1,-1 };
int dy[] = { 0,-1,1,0,0 };

struct shark
{
	int r;
	int c;
	int s;
	int d;
	int z;
};

vector <shark> v;

void eat(int x) {
	for (int j = 0; j < C; j++) {
		if (map[x][j] == 9) {
			res += v[x].z;
			break;
		}
	}
}

void move() {
	for (int i = 0; i < M; i++) {
		map[v[i].r][v[i].c] = 0;
		int x = v[i].r; int y = v[i].c;
		if (v[i].d == 1 || v[i].d == 2) {
			for (int j = 0; j < v[i].s; j++) {
				x = x + dx[v[i].d];
				if (x >= 0 && x < R) {
					v[i].r = x;
				}
				else {
					x = x - dx[v[i].d];
					switch (v[i].d)
					{
					case 1:
						v[i].d = 2;
						x = x + dx[v[i].d];
					case 2:
						v[i].d = 1;
						x = x + dx[v[i].d];
					default:
						break;
					}
					v[i].r = x;
				}
			}
			if(map[v[i].r][v[i].c] == 9)
			map[v[i].r][v[i].c] = 9;
		}
	}
}

int main() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> r >> c;
		map[r][c] = 9;
		cin >> s >> d >> z;
		v.push_back({ r,c,s,d,z });
	}
	for (int i = 0; i < C; i++) {
		if (i == 0) {
			eat(i);
		}
		else {
			memset(map, 0, sizeof(map));
		}
	}


}