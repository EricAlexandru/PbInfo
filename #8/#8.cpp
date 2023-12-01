#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("maxim3.in");
    fin >> ws;
    int numar1, numar2, numar3;
    fin >> numar1 >> numar2 >> numar3;
    fin.close();

    int maxim = numar1;
    if (numar2 > maxim) maxim = numar2;
    if (numar3 > maxim) maxim = numar3;

    ofstream fout("maxim3.out");
    fout << maxim << endl;
    fout.close();

    return 0;
}
