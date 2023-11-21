#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("adiacenta.in");
ofstream fout("adiacenta.out");

int n,a[105][105];

int main(){
    int m , i , j;
    fin >> n >> m;
    for(int l = 1; l <= m ; l++)
    {
        fin >> i >> j;
        a[i][j] = a[j][i] = 1;
    }
    for(int i = 1 ;  i <= n ; i++){
        for(int j = 1; j <= n ; ++j)
            fout << a[i][j] << " ";
        fout << endl;
    }
}