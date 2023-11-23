#include <iostream>
using namespace std;

int a[105][105];

int main(){
    int n, k = 1;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(i == j && a[i][j] != 0) k = 0;
        }
    for(int i = 1; i < n; i++)
        for(int j = i + 1; j <= n; j++){
            if(a[i][j] < 0 || a[i][j] > 1) k = 0;
            if(a[i][j] != a[j][i]) k = 0;
        }
    cout << k;
}