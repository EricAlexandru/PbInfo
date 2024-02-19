#include <iostream>
using namespace std;

int x[10] , n;

void afisare(int k)
{
    for(int i = 1 ; i <= k ; ++i)
        cout << x[i] << ' ';
    cout << '\n';
}

void back(int k)
{
    for(int i = x[k - 1] + 1 ; i <= n ; ++i)
    {
        x[k] = i;
        afisare(k);
        back(k + 1);
    }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}