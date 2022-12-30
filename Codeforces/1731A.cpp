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
        int n;
        cin >> n;
        ll result = 1;    
        for(int i = 0;i < n;i++) {
            ll value;
            cin >> value;
            result *= value;
        }
        cout << (result + (n - 1)) * 2022 << endl;
    }
    return 0;
}
