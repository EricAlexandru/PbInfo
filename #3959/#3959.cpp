/// problema de 10/100
/*
#include <iostream>
#include <deque>
#include <fstream>
using namespace std;
int main(){
    ifstream fin ("maxsecvk.in");
    ofstream fout ("maxsecvk.out");
    int i, n, k, x, maxi;
    fin >> n >> k;
    deque <int> q, rez;
    while(fin >> x)
        q.push_back(x);
    
    while(q.size() >= k){
        maxi = 0;
        for(i = 0; i < k; i++){
            if(q[i] > maxi)
                maxi = q[i];
        }
        rez.push_back(maxi);
        q.pop_front();
    }

    while(!rez.empty()){
        fout << rez.front() << ' ';
        rez.pop_front();
    } 
} 
*/

///problema de 100/100
#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ifstream fin ("maxsecvk.in");
    ofstream fout ("maxsecvk.out");
    int n, k;
    fin >> n >> k;
    
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }

    deque<int> valoriMax;

    for (int i = 0; i < k; i++) {
        while (!valoriMax.empty() && v[i] >= v[valoriMax.back()]) {
            valoriMax.pop_back();
        }
        valoriMax.push_back(i);
    }

    for (int i = k; i < n; i++) {
        fout << v[valoriMax.front()] << " ";

        while (!valoriMax.empty() && valoriMax.front() <= i - k) {
            valoriMax.pop_front();
        }

        while (!valoriMax.empty() && v[i] >= v[valoriMax.back()]) {
            valoriMax.pop_back();
        }

        valoriMax.push_back(i);
    }

    fout << v[valoriMax.front()] << ' ';

}
