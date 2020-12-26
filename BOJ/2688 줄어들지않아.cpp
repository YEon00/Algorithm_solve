#include <iostream>
using namespace std;

int tc, n;
long long sum, d[65][10];

int main() {
    for (int i = 0; i <= 9; i++) {
        d[1][i] = 1;
    }
    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                d[i][j] += d[i - 1][k];
            }
        }
    }
    cin >> tc;
    while(tc--) {
        cin >> n;
        sum = 0;
        for (int i = 0; i <= 9; i++) {
            sum += d[n][i];
        }
        cout << sum << '\n';
    }

    return 0;
}