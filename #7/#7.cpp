#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("maxim.in");
    int numar1, numar2;
    fin >> numar1 >> numar2;
    fin.close();

    int maxim = (numar1 > numar2) ? numar1 : numar2;

    ofstream fout("maxim.out");
    fout << maxim << endl;
    fout.close();

    return 0;
}
