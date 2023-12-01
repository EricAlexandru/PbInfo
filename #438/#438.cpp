#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("componenteconexe.in");
ofstream fout("componenteconexe.out");

int a[105][105], v[105];

void dfs(int k, int n, vector<int>& componenta) {
    v[k] = 1;
    componenta.push_back(k);

    for (int i = 1; i <= n; i++)
        if (a[k][i] == 1 && !v[i])
            dfs(i, n, componenta);
}

int main() {
    int n, i, j, nrcomponente = 0;
    fin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = 0;

    while (fin >> i >> j) {
        a[i][j] = a[j][i] = 1;
    }

    vector<vector<int> > componente;  

    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            nrcomponente++;
            vector<int> componenta;
            dfs(i, n, componenta);
            sort(componenta.begin(), componenta.end());
            componente.push_back(componenta);
        }
    }

    fout << nrcomponente << endl;

    for (size_t i = 0; i < componente.size(); i++) {
        for (size_t j = 0; j < componente[i].size(); j++) {
            fout << componente[i][j] << " ";
        }
        fout << endl;
    }

    return 0;
}
