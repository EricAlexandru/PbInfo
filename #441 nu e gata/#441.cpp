#include <fsteream>
using namespace std;

ifstream fin("componenteconexe1.in");
ofstream fout("componenteconexe1.out");

int n, a[105][105];

int main(){
    int i, j;
    fin >> n;
    while(fin >> i >> j)
        a[i][j] = a[j][i] = 1;
    
}