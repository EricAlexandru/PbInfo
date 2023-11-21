/// 5/100p, depaseste limita de timp
/*

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

    long long sumaMax = 0;

    for (int i = 0; i < n; i++) {
        long long sum = 0;

        for (int j = i; j < min(i + w, n); j++) {
            sum += q[j];
            
            if (j - i + 1 >= k) {
                sumaMax = max(sumaMax, sum);
            }
        }
    }
    
    cout << sumaMax << endl;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, K, W;
    cin >> N >> K >> W;

    vector<int> nr(N);
    for (int i = 0; i < N; ++i) {
        cin >> nr[i];
    }

    long long sumaMax = 0;
    long long sumaCurenta = 0;

    for (int i = 0; i < K; ++i) {
        sumaCurenta += nr[i];
    }

    sumaMax = sumaCurenta;

    for (int i = K; i < N; ++i) {
        sumaCurenta += nr[i];

        if (i >= W) {
            sumaCurenta -= nr[i - W];
        }

        sumaMax = max(sumaMax, sumaCurenta);
    }

    cout << sumaMax << endl;
}



