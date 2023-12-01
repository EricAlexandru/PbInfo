#include <iostream>
using namespace std;

int divideSuma(int v[], int st, int dr){
    if(st == dr) return v[st];
    else {
        int m = (st + dr) / 2;
        int s1 = divideSuma(v, st, m);
        int s2 = divideSuma(v, m + 1, dr);
        return s1 + s2;
    }
}

int main(){
    int n, v[1111], i;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    int x = divideSuma(v, 1, n);
    cout << x;
}