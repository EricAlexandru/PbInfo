/// 5/100p, depaseste limita de timp


#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, k, w;
    cin >> n >> k >> w;
    
    deque<int> q; 
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push_back(x);
    }

    long long maxSum = 0;

    for (int i = 0; i < n; i++) {
        long long sum = 0;

        for (int j = i; j < min(i + w, n); j++) {
            sum += q[j];
            
            if (j - i + 1 >= k) {
                maxSum = max(maxSum, sum);
            }
        }
    }
    
    cout << maxSum << endl;
}
