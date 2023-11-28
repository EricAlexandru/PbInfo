#include <fstream>
using namespace std;

ifstream fin("gradk.in");
ofstream fout("gradk.out");

int a[105][105];

int main(){
    int n, k, i, j, c = 0;
    fin >> n >> k;
    while(fin >> i >> j)
    {
        if(!a[i][j] && !a[j][i])
        {
            a[i][j]=a[j][i]=1;
            a[i][0]++;
            a[j][0]++;
        }
    }
    
    for(i = 1; i <= n; i++){
        if(a[i][0] == k) c++;
    }
    if(!c) fout << "NU EXISTA";
    else fout << c << ' ';
    for(i = 1; i <= n; i++){
        if(a[i][0] == k) 
            fout << i << ' ';
    }
}