#include <fstream>
#include <vector>
using namespace std;

ifstream fin("ccmax.in");
ofstream fout("ccmax.out");

int a[105][105], viz[105], n;
vector<int> v;

void dfs(int k)
{
    viz[k] = 1;
    v.push_back(k);
    for (int i = 1; i <= n; i++)
        if (a[k][i] && !viz[i])
            dfs(i);
}

int main()
{
    fin >> n;
    int i, j;
    while (fin >> i >> j)
        a[i][j] = a[j][i] = 1;

    int nrVf, nrVfMax = -1, nrComp;
    for (i = 1; i <= n; i++)
        if (!viz[i])
        {
            dfs(i);
            nrVf = v.size();
            if (nrVf > nrVfMax)
            {
                nrVfMax = nrVf;
                nrComp = 1;
            }
            else if (nrVf == nrVfMax)
            {
                nrComp++;
            }
            v.clear();
        }
    fout << nrVfMax << ' ' << nrComp;
}
