#include <iostream>
using namespace std;

void citireVect(int i, int n, int v[]){
    if(i <= n){
        cout << "v["<<i<<"] = ";
        cin >> v[i];
        citireVect(i + 1, n, v);
    }
}

int divideSuma7(int v[], int st, int dr)
{
    if(st == dr){
        if(v[st] % 7 == 0)
            return v[st]; 
        else return 0;
    }
        
    else
    {
        int m = (st + dr) / 2; 
        int s1 = divideSuma7(v, st, m); 
        int s2 = divideSuma7(v, m + 1, dr); 
        return s1 + s2; 
    }
}

int prim(int x) {
    if (x < 2) return 0;
    
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0) return 0;
    
    return 1;
}

int divideProdValPrime(int v[], int st, int dr){
    if(st == dr){
        if(prim(v[st]))
            return v[st];
        else 
            return 1;
    }
    else {
        int m = (st + dr) / 2;
        int p1 = divideProdValPrime(v, st, m);
        int p2 = divideProdValPrime(v, m + 1, dr);
        return p1 * p2;
    }
}

    int nrCifre(int x){
        if(x > 0){
            return 1 + nrCifre(x / 10);
        }
        else return 0;
    }

    int divideNrImpCf(int v[], int st, int dr){
    if(st == dr){
        return nrCifre(v[st]) % 2;
    }
    else {
        int m = (st + dr) / 2;
        int s1 = divideNrImpCf(v, st, m);
        int s2 = divideNrImpCf(v, m + 1, dr);
        return s1 + s2;
    }
}

    int invers(int x, int inv){
        if(x){
            inv = inv * 10 + x % 10;
            return invers(x / 10, inv);
        }
        else return inv;
    }

    int dividePalindromMax(int v[], int st, int dr){
        if(st == dr){
            if(v[st] == invers(v[st], 0))
                return v[st];
            else return -32768;
        }
        else {
            int m = (st + dr) / 2;
            int s1 = dividePalindromMax(v, st, m);
            int s2 = dividePalindromMax(v, m + 1, dr);
            if(s1 < s2) return s2;
            else return s1;
        }
    }

    int sumaDivizorilor(int x, int d) {
    if (d <= x / 2) {
        if (x % d == 0) {
            return d + sumaDivizorilor(x, d + 1);
        } else {
            return sumaDivizorilor(x, d + 1);
        }
    } else {
        return 0;
    }
}

    int divideCelMaiMicNrPerf(int v[], int st, int dr){
        if(st == dr){
            if(v[st] == sumaDivizorilor(v[st], 1))
                return v[st];
            else return -1;
        }
        else {
            int m = (st + dr) / 2;
            int s1 = divideCelMaiMicNrPerf(v, st, m);
            int s2 = divideCelMaiMicNrPerf(v, m + 1, dr);
            if(s1 < s2)
                return s1;
            else 
                return s2;
        }
    }

int main()
{
    int v[] = {0, 7, 14, 5, 2, 12321, 6, 8}, n = 8;
    cout << "n = ";
    cin >> n;
    citireVect(1, n, v);
    cout << "suma nr % 7 este:" << divideSuma7(v, 1, n) << endl;
    cout << "produsul nr prime este:" << divideProdValPrime(v, 1, n);
    cout << nrCifre(12345);
    cout << divideNrImpCf(v, 1, n) << " nr au nr imp de cifre";
    cout << "cel mai mare nr invers este:" << dividePalindromMax(v, 1, n);
    cout << divideCelMaiMicNrPerf(v, 1, n);
    return 0;
}