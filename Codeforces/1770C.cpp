#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <iterator>
#include <random>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  while (b != 0) {
    ll tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

const ll RANGE = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    std::mt19937_64 eng(random_device{}());
    int T;
    cin >> T;
    for(int c = 0;c < T;c++) {
        int n;
        cin >> n;
        vector<ll> values(n);
        bool hasSame = false;
        for(int i = 0;i < n;i++) {
            cin >> values[i];
            for(int j = i - 1;j >= 0;j--) {
                if(values[i] == values[j]) hasSame = true;
            }
        }
        if(hasSame) {
            cout << "NO" << endl;
            continue;
        }
        bool invalid = false;
        for(int i = 2;i <= ceil(n * 1.00 / 2);i++) {
            vector<int> cnts(i);
            for(auto v : values) cnts[v % i]++;
            bool flag = false;
            for(int j = 0;j < i;j++) {
                if(cnts[j] < 2) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                invalid = true;
                break;
            }
        }
        if(invalid) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}
