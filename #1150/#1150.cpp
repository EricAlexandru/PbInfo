#include <iostream>
using namespace std;

int divide(int v[], int st, int dr){
    if(st == dr) return v[st] % 2 == 0;
    else {
        int m = (st + dr) / 2;
        bool pareSt = divide(v, st, m);
        bool pareDr = divide(v, m + 1, dr);
        return pareDr && pareSt;
    }
}

int main(){
    int n, v[111], i;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    if(divide(v, 1, n))
        cout << "DA";
    else
        cout << "NU";
}