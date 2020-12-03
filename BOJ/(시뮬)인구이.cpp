#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N, L, R;
int area[51][51];
int unionNation[51][51];
bool visit[51][51];

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

int nationCnt = 0;
int peopleCnt = 0;

void dfs(int r, int c, int n) {
    unionNation[r][c] = n;
    visit[r][c] = true;
    peopleCnt += area[r][c];
    nationCnt++;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
        if (visit[nr][nc]) continue;
        int diff = abs(area[r][c] - area[nr][nc]);
        if (diff >= L && diff <= R) {
            dfs(nr, nc, n);
        }
    }
}

int main() {
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> area[i][j];
        }
    }
    int result = 0;
    while (true) {
        memset(visit, false, sizeof(visit));
        int union_cnt = 0;
        map<int, int> mp;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (visit[i][j]) continue;
                peopleCnt = 0;
                nationCnt = 0;
                dfs(i, j, union_cnt);
                mp[union_cnt] = peopleCnt / nationCnt;
                union_cnt++;
            }
        }
        
        if (union_cnt == N * N) break;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                area[i][j] = mp[unionNation[i][j]];
            }
        }
        result++;
    }
    cout << result << endl;
    return 0;
}