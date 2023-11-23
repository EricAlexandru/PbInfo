#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("legos.in");
ofstream fout("legos.out");

int c;
long long n;

int main(){
    fin >> c >> n;
    if(c == 1){
        fout<<(long long)pow((int)sqrt(n),2);
    }

    else if(c == 2){
        if(n < 16)
            fout << 9;
        else if(n < 22)
            fout << 16;
        else
            fout << (n - 9) / 13 * 13 + 9;
    }

    if(c == 3){
        int c = 0;
        int i;
        for(i = 3; i * i < n; i++)
            if(n % i == 0)
                c += 2;
        if(i * i == n)
            c++;
        fout << c;
    }
}