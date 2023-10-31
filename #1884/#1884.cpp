#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    stack<int> stiva, rezultat;
    int rezInv[100010];
    int i = 0;
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        stiva.push(x);
    }
    
    while (!stiva.empty()) {
        int vf = stiva.top();
        stiva.pop();
        
        while (i > 0 && vf >= rezInv[i - 1]) {
            i--;
        }
        
        if (i == 0) {
            rezultat.push(-1);
        } else {
            rezultat.push(rezInv[i - 1]);
        }
        
        rezInv[i] = vf;
        i++;
    }
    
    while(!rezultat.empty()){
        cout << rezultat.top() << ' ';
        rezultat.pop();
    }
}
