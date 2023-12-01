#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("sum.in");

    int numar1, numar2;
    fin >> numar1 >> numar2;
    int suma = numar1 + numar2;
    ofstream fout("sum.out");
    fout << suma << endl;
    fout.close();
}
