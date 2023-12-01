#include <iostream>
#include <cmath>
using namespace std;

int prim(int x){
    if(x<2)
        return 0;
    for(int d=2;d*d<=x;d++)
        if(x%d==0)
            return 0;
    return 1;
}

int sumprim(int v[], int st, int dr){
    if(st == dr && prim(v[st]) == 1)
        return v[st];
     else if(st == dr)
            return 0;
         else{
            int mij = (st + dr) / 2;
            return sumprim(v, st, mij) + sumprim(v, mij+1, dr);
         }
}

int main() {
    int n, v[1111];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int x = sumprim(v, 1, n);
    cout << x;
}
