#include <fstream>
#include <vector>
using namespace std;

ifstream fin("componenteconexe1.in");
ofstream fout("componenteconexe1.out");
int v[100], a[100][100], n, c = 0;
vector<int> muchii;

void dfs(int start, int k) {
    v[k] = start;  
    for (int i = 1; i <= n; i++)
        if (a[i][k] == 1 && v[i] == 0) {
            dfs(start, i);
        }
}

int main(){
    int i, j;
    fin >> n;
    while(fin >> i >> j)
        a[i][j] = a[j][i] = 1;

    for(i = 1; i <= n; i++)
        if(!v[i])
        {
            dfs(i, i);
            c++;
            muchii.push_back(i);
        }

    fout << c - 1 << endl;
    int t = muchii.size();
    for(i = 1; i < t; i++)
        fout << muchii[0] << ' ' << muchii[i] << endl;

    return 0;
}
