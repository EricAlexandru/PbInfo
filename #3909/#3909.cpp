#include <iostream>
using namespace std;

int a, b, n, x[10];

void afisare()
{
    for(int i = 1 ; i <= n ; i++)
        cout << x[i] << " ";
    cout << endl;
}

int valid(int k)
{
    for(int i = 1 ; i < k ; i++)
        if(x[i] == x[k]) return 0;
    return 1;
}

void back(int k)
{
    for(int i = a ; i <= b ; i++)
    {
        x[k] = i;
        if(valid(k))
            if(k == n) afisare();
            else back(k + 1);
    }
}

int main()
{
    cin >> a >> b;
    n = b - a + 1;
    back(1);
    return 0;
}