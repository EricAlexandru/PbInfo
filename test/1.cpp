#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, x = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        x *= i;
        cout << x << ' ';
    }
}