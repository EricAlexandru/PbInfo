#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

ifstream fin("gasti.in");
ofstream fout("gasti.out");

int c;
vector<vector<int> > v;
vector<bool> viz;

void dfs(int k) {
    viz[k] = true;
    c++;

    for (int i = 0; i < v[k].size(); ++i) {
        int vecin = v[k][i];
        if (!viz[vecin]) {
            dfs(vecin);
        }
    }
}

int main() {
    int n, m, nrCompConexe = 0;
    fin >> n >> m;

    v.resize(n + 5);
    viz.resize(n + 5, false); 

    int i, j;
    while (fin >> i >> j) {
        v[i].push_back(j);
        v[j].push_back(i);
    }

    int maxi1, maxi2, nrDeMaxi2;
    maxi1 = maxi2 = -1;
    
    for (i = 1; i <= n; i++) {
        if (!viz[i]) {
            c = 0;
            nrCompConexe++;
            dfs(i);
            if (c > maxi1) {
                maxi2 = maxi1;
                maxi1 = c;
                nrDeMaxi2 = 1;
            } else if (c > maxi2) {
                maxi2 = c;
                nrDeMaxi2 = 1;
            } else if (c == maxi2) {
                nrDeMaxi2++;
            }
        }
    }
    
    long long posibilitati = 0;
    //posibilitati += (maxi1 * (maxi1 - 1) / 2) - (c * (c - 1) / 2);
    //posibilitati *= nrDeMaxi2;

    fout << nrCompConexe << ' ' << ((long long)maxi1 * maxi2 * nrDeMaxi2) % 666013;
    /// sa pun %mod pt fiecare si dupa sa inmultesc

    return 0;
}

