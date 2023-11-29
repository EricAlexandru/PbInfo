#include <fstream>
#include <queue>
using namespace std;

ifstream fin("BFS.in");
ofstream fout("BFS.out");

int a[105][105], v[105], n;

void bfs(int start){
    int i, k, c = 0;
    queue<int> x;
    
    x.push(start);
    v[start] = 1;
    fout << start << ' ';

    while(!x.empty()){
        k = x.front();
        x.pop();
        for(i = 1; i <= n; i++)
            if(!v[i] && a[k][i]){
                v[i] = 1;
                x.push(i);
                fout << i << ' ';
                c++;
            }
    }
}

int main(){
    int m, x, i, j;
    fin >> n >> m >> x;
    while(fin >> i >> j){
        a[i][j] = a[j][i] = 1;
    }
    bfs(x);
}