#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int cnt[10];

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
        int result = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j <= 9;j++) cnt[j] = 0;
            int curDis = 0, maxCnt = 0;
            for(int j = i;j <= i + 101 && j < n;j++) {
                int val = s[j] - '0';
                if(cnt[val] == 0) curDis++;
                cnt[val]++;
                maxCnt = max(maxCnt, cnt[val]);
                if(maxCnt <= curDis) result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
