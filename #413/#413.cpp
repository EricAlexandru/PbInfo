#include <fstream>
#include <climits>
using namespace std;
ifstream fin("adiacenta1.in");
ofstream fout("adiacenta1.out");
int a[101][101];
int main(){
    int n = INT_MIN, i, j;
    while(fin >> i >> j){
        a[i][j] = 1;
        a[j][i] = 1;
        n = max(n, max(i, j));
    }

    for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                fout << a[i][j] << " ";
            fout << endl;
        }
}