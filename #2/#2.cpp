#include <iostream>

using namespace std;

int main() {
    int n, suma = 0;
    cin >> n;

    for (int i = 0, numar; i < n; i++) {
        cin >> numar;
        suma += numar;
    }

    cout << suma << endl;

}
