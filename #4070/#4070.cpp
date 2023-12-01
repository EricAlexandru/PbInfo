#include <iostream>
using namespace std;

int a[105][105];

int main() {
    int n, m, k, i, j;
    cin >> n >> m >> k;
    while (m) {
        cin >> i >> j;
        a[i][j] = a[j][i] = 1;
        m--;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i % k == 0 || j % k == 0) {
                a[i][j] = a[j][i] = 0;
            }
        }
    }
    int c = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i][j]) {
                c++;
            }
        }
    }
    cout << c / 2;
}
