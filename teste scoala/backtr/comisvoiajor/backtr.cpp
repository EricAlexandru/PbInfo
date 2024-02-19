#include <fstream>
using namespace std;

ifstream fin("comisvoiajor.in");
ofstream fout("comisvoiajor.out");

int a[105][105], n, st[105];

void afisare()
{fout << endl;
    for(int i = 1 ; i <= n ; i++)
        fout << st[i] << " ";
}

int valid(int k)
{
    for(int i = 1; i < k; i++)
        if(st[i] == st[k])
            return 0;
        if(!a[st[k]][st[k - 1]])
            return 0;
        if(k == n && !a[st[k]][st[1]])
            return 0;
        return 1;
}

void back(int k)
{
    for(int i = 1 ; i <= 4 ; i++)
    {
        st[k] = i;
        if(valid(k)){ fout << "da";
            if(k == n) afisare();
            else back(k + 1);
        }
    }
}

int main()
{
    fin >> n;
    int i, j;
    while(fin >> i >> j)
        a[i][j] = a[j][i] = 1;
     back(1);
    return 0;
}