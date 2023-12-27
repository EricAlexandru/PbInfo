#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("componenteconexe3.in");
ofstream fout("componenteconexe3.out");

int a[105][105];
bool vizitat[105];
int n;

void dfs(int k, int &nrNoduri, int &reprezentant)
{
    vizitat[k] = true;
    nrNoduri++;
    reprezentant = min(reprezentant, k);

    for (int i = 1; i <= n; i++)
    {
        if (a[k][i] == 1 && !vizitat[i])
        {
            dfs(i, nrNoduri, reprezentant);
        }
    }
}

int main()
{
    fin >> n;
    int i, j;

    while (fin >> i >> j)
    {
        a[i][j] = a[j][i] = 1;
    }

    int maxNrNoduri = 0;
    int reprezentantMax = -1;

    for (int nod = 1; nod <= n; nod++)
    {
        if (!vizitat[nod])
        {
            int nrNoduri = 0;
            int reprezentant = n + 1; 
            dfs(nod, nrNoduri, reprezentant);

            if (nrNoduri > maxNrNoduri || (nrNoduri == maxNrNoduri && reprezentant < reprezentantMax))
            {
                maxNrNoduri = nrNoduri;
                reprezentantMax = reprezentant;
            }
        }
    }

    fout << reprezentantMax << " " << maxNrNoduri << "\n";

    return 0;
}
