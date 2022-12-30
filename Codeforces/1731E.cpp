#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_V = 1e6;

bool isNotPrime[MAX_V + 1];
ll ph[MAX_V + 1];
vector<int> primes;

void init() {
    ph[1] = 0;
    for(int i = 2;i <= MAX_V;i++) {
        if(!isNotPrime[i]) {
            primes.push_back(i);
            ph[i] = i - 1;
        }
        for(int j = 0;j < static_cast<int>(primes.size());j++) {
            if(1LL * i * primes[j] > MAX_V) break;
            isNotPrime[i * primes[j]] = true;
            if(i % primes[j] == 0) {
                ph[primes[j] * i] = ph[i] * primes[j];
                break;
            } else {
                ph[primes[j] * i] = ph[i] * (primes[j] - 1);
            }
        }
    }
    for(int i = 2;i <= MAX_V;i++) {
        ph[i] += ph[i - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    primes.insert(primes.begin(), 1);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll m, cost = 0;
        cin >> m;
        for(int i = n;i >= 2;i--) {
            // int cnt = n / i;
            // ll allEdges = 1LL * cnt * (cnt - 1) / 2;
            ll allEdges = ph[n / i];
            ll possible = allEdges / (i - 1);
            if(possible * (i - 1) <= m) {
                m -= possible * (i - 1);
                cost += possible * i;
            } else {
                ll maxPossible = m / (i - 1);
                m -= maxPossible * (i - 1);
                cost += maxPossible * i;
            }
            if(m == 0) break;
        }
        cout << (m == 0 ? cost : -1) << endl;
    }

    return 0;
}
