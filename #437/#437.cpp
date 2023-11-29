#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("conex.in");
ofstream fout("conex.out");
int v[100],a[100][100],n;

void dfs(int k){
    v[k] = 1;
    for(int i = 1; i <= n; i++)
        if(a[i][k] == 1 && v[i] == 0){
            dfs(i);
    }
}
int main(){
    int i, j, s = 0;
    fin >> n;
    while(fin >> i >> j){
        a[i][j] = a[j][i] = 1;
    }
    dfs(1);
    for(i = 1; i <= n; i++)
    s += v[i];
        if(s == n)
        fout << "DA";
        else
        fout<<"NU";
}