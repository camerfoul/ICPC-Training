#include <iostream>
#include <iomanip>
#include <vector>

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
        vector<int> values(n);
        for(int i = 0;i < n;i++) {
            int value;
            cin >> value;
            values[i] = value;
        }
        cout << (values[0] == 1 ? "Yes" : "No") << endl;
    }
    return 0;
}