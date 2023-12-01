#include <iostream>

using namespace std;

int main() {
    unsigned int numar;
    cin >> numar;

    int suma = 0;

    while (numar > 0) {
        suma += numar % 10;
        numar /= 10;
    }

    cout << suma << endl;

    return 0;
}
