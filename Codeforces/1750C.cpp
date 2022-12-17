#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool value = false, invalid = false;
        for(int i = 0;i < n;i++) {
            bool newValue = a[i] != b[i];
            if(i == 0) {
                value = newValue;
                continue;
            }
            if(value != newValue) {
                cout << "NO" << endl;
                invalid = true;
                break;
            }
        }
        if(invalid) continue;
        cout << "YES" << endl;
        vector<int> values;
        for(int i = 0;i < n;i++) {
            if(a[i] != '1') continue;
            values.push_back(i + 1);
            value = !value;
        }
        if(!value) {
            cout << values.size() << endl;
            for(auto &v : values) {
                cout << v << " " << v << endl;
            }
            continue;
        }
        cout << values.size() + 3 << endl;
        for(auto v : values) {
            cout << v << " " << v << endl;
        }
        cout << 1 << " " << 1 << endl;
        cout << 2 << " " << n << endl;
        cout << 1 << " " << n << endl;
    }
    return 0;
}
