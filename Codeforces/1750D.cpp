#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int MOD = 998244353;

void prime_factor(int n, vector<int> &primes) {
    if(n < 2) return;
    int upperBound = static_cast<int>(ceil(sqrt(n)));
    for(int i = 2;i <= upperBound;i++) {
        bool exist = false;
        while(n % i == 0) {
            n /= i;
            exist = true;
        }
        if(exist) primes.push_back(i);
    }
    if(n != 1) primes.push_back(n);
}

int count_one(int value) {
    int result = 0;
    while(value) {
        value = value & (value - 1);
        result++;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> values(n);
        bool valid = true;
        for(int i = 0;i < n;i++) {
            cin >> values[i];
            if(i != 0 && values[i - 1] % values[i] != 0) valid = false;
        }
        if(!valid) {
            cout << 0 << endl;
            continue;
        }
        long long result = 1;
        vector<int> primes;
        for(int i = 1;i < n;i++) {
            int value = values[i - 1] / values[i];
            if(value == 1) {
                result = (result * (m / values[i])) % MOD;
                continue;
            }
            primes.clear();
            prime_factor(value, primes);
            int count = primes.size(), tmpResult = 0, upperBound = m / values[i];
            for(int i = 1;i < (1 << count);i++) {
                int primeMul = 1, oneCnt = 0;
                for(int j = 0;j < count;j++) {
                    if(!((1 << j) & i)) continue;
                    primeMul *= primes[j];
                    oneCnt++;
                }
                tmpResult += ((oneCnt & 1) ? 1 : -1) * (upperBound / primeMul);
            }
            result = (result * (upperBound - tmpResult)) % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
