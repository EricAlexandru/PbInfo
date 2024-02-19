///RECURSIV
/*
#include <iostream>
using namespace std;

int st[100], n;
char c[] = {'X', 'A', 'B', 'C', 'D', 'E'};

void init(){
    cout << "n=";
    cin >> n;
}

void tipar(int k)
{
    for(int i = 1; i <= k; i++)
        cout << c[st[i]] << ' ';

    cout << endl;
}

bool solutie(int k){
    return(k == 4);
}

bool valid(int k){
    if(k > 1)
        if((st[k] == 1 && st[k-1] == 1) || (st[k] == 1 && st[k-1] == 5) || (st[k] == 5 && st[k-1] == 1) || (st[k] == 5 && st[k-1] == 5))
            return false;
    return true;
}


void back(int k){
    for(int i = 1 ; i <= 5 ; ++i)
    {
        st[k]=i;
        if( valid(k) )
            if(solutie(k))
                tipar(k);
            else
                back(k+1);
    }
}
int main(){
    //citire date de intrare
    back(1);
    return 0;
}
*/












///ITERATIV
#include <iostream>
using namespace std;

int st[100], n;

void init(int k){
    st[k] = 0;
}

bool succesor(int k){
    if(st[k] < n){
        st[k]++;
        return 1;
    }
    else return 0;
}

bool valid(int k){
    bool ev = 1;
    for(int i = 1; i < k; i++)
        if(st[i] == st[k])
            ev = 0;
    // ... alte conditii...
    return ev;
}

bool solutie(int k){
    return (k == n);
}

void tipar(int k){
    for(int i = 1; i <= k; i++)
        cout << st[i] << ' ';
    cout << endl;
}

void back(int k){
    k = 1;
    init(k);
    while(k > 0){
        if(succesor(k)){
            if(valid(k)){
                if(solutie(k))
                    tipar(k);
                else{
                    k++;
                    init(k);
                }
            }
            else k--;
        }
    }
}

int main(){
    cin >> n;
    back(n);
    return 0;
}