#include <iostream>
using namespace std;

int binarySearch(int v[], int st, int dr, int x) {
    if (st <= dr) {
        int m = st + (dr - st) / 2;
        if (v[m] == x) {
            return 1;
        } else if (v[m] < x) {
            return binarySearch(v, m + 1, dr, x);
        } else {
            return binarySearch(v, st, m - 1, x);
        }
    }
    return 0;
}

int main() {
    int n, m, a[25555], b[200099], i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (i = 1; i <= m; i++)
        cin >> b[i];

    for (i = 1; i <= m; i++)
        cout << binarySearch(a, 1, n, b[i]) << ' ';

    return 0;
}
