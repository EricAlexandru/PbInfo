#include <algorithm>
#include <fstream>
#include <utility>
using namespace std;

int main(){
    ifstream fin("proiecte.in");
    ofstream fout("proiecte.out");

    int n, x, i;
    vector<pair <int, int> > v;
    fin >> n;
    for(i = 1; i <= n; i++){
        fin >> x;
        v.push_back(make_pair(x, i));
    }
    sort(v.begin(), v.end());
    for(i = 0; i < v.size(); i++)
        fout << v[i].second << ' ';
}