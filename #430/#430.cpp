#include <fstream>
using namespace std;

ifstream fin("izolate.in");
ofstream fout("izolate.out");

int a[101][101];

int main() {
    int n, i, j, izolate = 0;
    fin >> n;
    while(fin >> i >>j) {
        a[i][j] = a[j][i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        int k = 0;
        for(int j = 1; j <= n; j++)
            if(a[i][j])
                k += 1;
        if(k == 0)
            izolate += 1;
    }
    fout << izolate << " ";
    for(int i = 1; i <= n; i++) {
        int k = 0;
        for(int j = 1; j <= n; j++)
            if(a[i][j])
                k += 1;
        if(k == 0)
            fout << i << " ";
    }
}