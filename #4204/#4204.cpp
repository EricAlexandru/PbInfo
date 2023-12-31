#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("estearbore.in");
ofstream fout("estearbore.out");

int a[105][105], v[105], n;

void dfs(int k)
{
  v[k]=1; 
  for(int i=1;i<=n;i++) 
    if(a[k][i] && !v[i])
      dfs(i); 
}

int main()
{
    int c = 0;
    fin >> n;
    int i, j;
    while(fin >> i >> j)
        if(!a[i][j])
        {
            a[i][j] = a[j][i] = 1;
            c++;
        }
    if(n != c + 1)
    {
        fout << "NU";
        return 0;
    }

    dfs(1);

    for(i = 1; i <= n; i++)
        if(!v[i])
        {
            fout << "NU";
            return 0;
        }
    
    fout << "DA";
}