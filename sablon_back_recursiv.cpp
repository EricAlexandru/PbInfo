#include <iostream>
using namespace std;

int st[100], n;

void init(){
    n = 5;
}

void tipar(int k)
{
    // afișare/prelucrare soluția finală curentă
}

bool solutie(int k){
    return(k == n);
}

bool valid(int k){
    //verificam sa nu se repete, toate conditiile, etc
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
    init();
    back(1);
    return 0;
}