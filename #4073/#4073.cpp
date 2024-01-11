#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("componenteconexe5.in");
ofstream fout("componenteconexe5.out");

int a[1005][1005], v[1005], numarCopmponente[1005], n;
vector <int> componenteConexe;

void dfs(int k)
{
  v[k] = 1;
  componenteConexe.push_back(k);
  for(int i = 1; i <= n; i++) 
    if(a[k][i] && !v[i])
      dfs(i);
}

int main()
{
    int m, i, j, q;
    fin >> n >> m;
    for(int z = 1; z <= m; z++)
    {
        fin >> i >> j;
        a[i][j] = a[j][i] = 1;
    }

    fin >> q;
    int sir[1005];
    for(i = 1; i <= q; i++)
        fin >> sir[i];

    for(i = 1; i <= n; i++)
        if(!v[i])
        {
            dfs(i);
            int size = componenteConexe.size();
            while(!componenteConexe.empty())
            {
                numarCopmponente[componenteConexe.back()] = size;
                componenteConexe.pop_back();
            }
        }

    for(i = 1; i <= q; i++)
        fout << numarCopmponente[sir[i]] << '\n';
}
