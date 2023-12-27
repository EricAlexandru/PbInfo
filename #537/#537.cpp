#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("componenteconexe2.in");
ofstream fout("componenteconexe2.out");

int a[105][105], viz[105], n;

void dfs(int k, vector<int>& visitedNodes)
{
    visitedNodes.push_back(k);
    viz[k] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (a[k][i] == 1 && find(visitedNodes.begin(), visitedNodes.end(), i) == visitedNodes.end())
        {
            dfs(i, visitedNodes);
        }
    }
}

int main()
{
    vector<int> visitedNodes;

    int muchii, nrNoduri, elMuchii = 0;

    fin >> n;
    int i, j;
    while (fin >> i >> j)
    {
        a[i][j] = a[j][i] = 1;
    }

    for (i = 1; i <= n; i++)
    {
        int grade = 0;
        for (j = 1; j <= n; j++)
            if (a[i][j])
                grade++;
        a[i][0] = grade;
    }

    for (i = 1; i <= n; i++)
    {
        if (viz[i] == 0)
        {
            dfs(i, visitedNodes);
            nrNoduri = visitedNodes.size();
            int sumaGrade = 0;
            for (j = 0; j < nrNoduri; j++)
                sumaGrade += a[visitedNodes[j]][0];
            muchii = sumaGrade / 2;
            elMuchii += muchii - (nrNoduri - 1);
            visitedNodes.clear(); 
        }
    }

    fout << elMuchii;

    return 0;
}
