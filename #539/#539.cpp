#include <fstream>
using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

int a[105][105], v[105];

void dfs(int k, int n){
    fout << k << ' ';
    v[k] = 1;
    for(int i = 1; i <= n; i++)
        if(a[k][i] == 1 && !v[i])
            dfs(i, n);
        
}

int main(){
    int n, m, x, i, j;
    fin >> n >> m >> x;
    while(fin >> i >> j){
        a[i][j] = a[j][i] = 1;
    }
    dfs(x, n);
}