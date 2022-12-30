#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll quickPow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        ll result = n;
        result = (result * (n + 1)) % MOD;
        result = (result * (4 * n - 1)) % MOD;
        result = (result * quickPow(6, MOD - 2)) % MOD;
        cout << (result * 2022) % MOD << endl;
    }
    return 0;
}
