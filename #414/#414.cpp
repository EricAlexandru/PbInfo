#include <iostream>
#include <fstream>
using namespace std;

int a[105][105];

int main(){
    ifstream fin("listavecini.in");
    ofstream fout("listavecini.out");
    int n, i, j;
    fin >> n;
    while(fin >> i >> j){
        a[i][j] = a[j][i] = 1;
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++)
            if(a[i][j]) a[i][0]++;
    }

    for(i = 1; i <= n; i++){
        fout << a[i][0] << ' ';
        for(j = 1; j <= n; j++)
            if(a[i][j]){
                fout << j << ' ';
            }
        fout << endl;
    }
}