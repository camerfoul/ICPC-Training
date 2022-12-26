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
        string s;
        cin >> s;
        vector<int> values(n + 1), sums(n + 1);
        for(int i = 1;i <= n;i++) {
            if(s[i - 1] == '(') values[i] = 1;
            else values[i] = -1;
            sums[i] = sums[i - 1] + values[i];
        }
        vector<int> sorted_sums = sums;
        sort(sorted_sums.begin(), sorted_sums.end());
        ll result = 0;
        for(int i = 0;i < static_cast<int>(sorted_sums.size());i++) {
            result += (i + 1) * 1LL * sorted_sums[i];
        }
        vector<pair<int, int> > mins;
        ll curMinSum = 0;
        for(int i = 0;i <= n ;i++) {
            int curCnt = 1;
            while(!mins.empty() && (--mins.end())->first >= sums[i]) {
                pair<int, int> lastVal = *(--mins.end());
                curMinSum -= lastVal.first * 1LL * lastVal.second;
                curCnt += lastVal.second;
                mins.pop_back();
            }
            mins.push_back(make_pair(sums[i], curCnt));
            curMinSum += sums[i] * 1LL * curCnt;
            result -= curMinSum;
        }
        cout << result << endl;
    }
    return 0;
}
