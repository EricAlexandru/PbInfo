#include <fstream>
using namespace std;

ifstream fin("lantq.in");
ofstream fout("lantq.out");

int a[50][50], n, m, q, ok;
int v[50], r[50];

void afis(int j){
    for(int i = 1; i <= j; i++)
        fout << v[i] << ' ';
    fout << '\n';
    ok = 1;
}

int OK(int j){
    if(j > 1)
        if(a[v[j - 1]][v[j]] == 0)
            return 0;
    return 1;
}

void back(int x){
    for(int i = 1; i <= n; i++)
        if(!r[i]){
            v[x] = i;
            r[i] = 1;
            if(OK(x))
                if(x > 1 && v[x] == q)
                    afis(x);
            else
                back(x + 1);
            r[i] = 0;
        }
}
int main(){
    int i, j;
    fin >> n >> m;
    for(int w = 1; w <= m; w++){
        fin >> i >> j;
        a[i][j] = a[j][i] = 1;
    }
    fin >> q;
    back(1);
    if(!ok)
        fout << "NU EXISTA";
}