#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <iterator>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        priority_queue<int, vector<int>, greater<int> > values;
        for(int i = 0;i < n;i++) {
            int value;
            cin >> value;
            values.push(value);
        }
        for(int i = 0;i < m;i++) {
            int value;
            cin >> value;
            values.pop();
            values.push(value);
        }
        ll result = 0;
        while(!values.empty()) {
            result += values.top();
            values.pop();
        }
        cout << result << endl;
    }
    return 0;
}
