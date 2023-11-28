#include <fstream>
using namespace std;

int a[105][105];

int main(){
    ifstream fin("grade.in");
    ofstream fout("grade.out");

    int n, i, j;
    fin >> n;

    while(fin >> i >> j){
        a[i][j] = a[j][i] = 1;
    }

    for(i = 1; i <= n; i++){
        int c = 0;
        for(j = 1; j <= n; j++)
            if(a[i][j])
                c++;
        fout << c << ' ';
    }
}