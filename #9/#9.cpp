#include <iostream>

using namespace std;

int main() {
    int numar1, numar2, numar3;
    cin >> numar1 >> numar2 >> numar3;

    int maxim = numar1;
    int minim = numar1;

    if (numar2 > maxim) maxim = numar2;
    if (numar3 > maxim) maxim = numar3;

    if (numar2 < minim) minim = numar2;
    if (numar3 < minim) minim = numar3;

    int diferenta = maxim - minim;

    cout << diferenta << endl;

    return 0;
}
