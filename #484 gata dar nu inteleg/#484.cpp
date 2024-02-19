#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int a[105][105], n;

void bfs(int start, int end, vector<int>& shortestPath)
{
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<vector<int> > parent(n + 1, vector<int>());


    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        for (int i = 0; i < parent[currentVertex].size(); ++i) {
            int neighbor = parent[currentVertex][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                parent[neighbor].push_back(currentVertex);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && a[currentVertex][i] == 1) {
                visited[i] = true;
                q.push(i);
                parent[i].push_back(currentVertex);
            }
        }
    }

    // Reconstruim cel mai scurt drum de la destinație la sursă
    int current = end;
    while (current != start) {
        shortestPath.push_back(current);
        current = parent[current][0];
    }
    shortestPath.push_back(start);
    reverse(shortestPath.begin(), shortestPath.end());
}

int main()
{
    ifstream fin("lantminim.in");
    ofstream fout("lantminim.out");

    int p, q, i, j;
    fin >> n >> p >> q;

    while (fin >> i >> j) {
        a[i][j] = a[j][i] = 1;
    }

    // Resetăm vectorul de vizitare pentru a putea rula BFS pe un alt subset de vârfuri
    vector<int> shortestPath;
    bfs(p, q, shortestPath);

    fout << shortestPath.size() << '\n';
    for (int i = 0; i < shortestPath.size(); ++i) {
        fout << shortestPath[i] << ' ';
    }

    fin.close();
    fout.close();

    return 0;
}
