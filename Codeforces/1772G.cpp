#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        ll x, y;
        cin >> x >> y;
        vector<ll> values(n);
        for(int i = 0;i < n;i++) {
            cin >> values[i];
        }
        sort(values.begin(), values.end());
        ll ans = 0;
        bool flag = true;
        for(int i = 0;i < n;i++) {
            if(x >= values[i]) {
                x++;
                ans++;
                if(x >= y) break;
                continue;
            }
            ll cycleChange = i - (n - i);
            if(cycleChange <= 0) {
                flag = false;
                break;
            }
            x -= n - i;
            ans += n - i;
            bool willExit = values[i] >= y;
            ll val = min(values[i], y), limit = val - i - 1 - x;
            ll cycles = limit / cycleChange;
            if(cycles < 0) cycles = 0;
            x += cycleChange * cycles;
            ans += n * cycles;
            while(x + i < val) {
                x += cycleChange;
                ans += n;
            }
            if(willExit) break;
            x += i + 1;
            ans += i + 1;
            if(x >= y) break;
        }
        if(!flag) cout << -1 << endl;
        else cout << ans + (y - x) << endl;
    }

    return 0;
}
