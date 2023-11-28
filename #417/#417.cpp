#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("gradmax.in");
ofstream fout("gradmax.out");

int x[101][101];

int main() {
    int n, a, b, gradmax = 0, kgradmax = 0;
    fin >> n;
    while(fin >> a >> b) {
        x[a][b] = 1, x[b][a] = 1;
    }
    for(int i = 1; i <= n; i++) {
        int k = 0;
        for(int j = 1; j <= n; j++)
            if(x[i][j])
                k += 1;
        if(k > gradmax)
            gradmax = k, kgradmax = 1;
        else if(k == gradmax)
            kgradmax += 1;
    }
    fout << kgradmax << " ";
    for(int i = 1; i <= n; i++) {
        int k = 0;
        for(int j = 1; j <= n; j++)
            if(x[i][j])
                k += 1;
        if(k == gradmax)
            fout << i << " ";
    }
}