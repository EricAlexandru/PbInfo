#include <fstream>
using namespace std;

ifstream fin("gradek.in");
ofstream fout("gradek.out");

int n, a[101][101], k, p;

int main(){
    int x, y;
    fin>>n>>k;
    while(fin >>x >> y){
        if(!a[x][y] && !a[y][x]){
            a[x][y] = a[y][x]=1;
            a[x][0]++;
            a[y][0]++;
        }
    }
    
    for(int i = 1; i <= n; i++)
            if(a[i][0] == a[k][0])
                p++;
    
    fout << p << '\n';
    for(int i = 1; i <= n; i++)
        if(a[i][0] == a[k][0])
            fout << i << ' ';
}