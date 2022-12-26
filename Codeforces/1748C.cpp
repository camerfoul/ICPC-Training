#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

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
        vector<ll> values(n + 1);
        vector<int> zeroPos;
        for(int i = 1;i <= n;i++) {
            cin >> values[i];
            if(values[i] == 0) zeroPos.push_back(i);
        }
        zeroPos.push_back(n + 1);
        map<ll, int> sumCnt;
        int result = 0;
        for(int i = 0;i < static_cast<int>(zeroPos.size()) - 1;i++) {
            sumCnt.clear();
            ll curVal = 0;
            int maxCnt = 0;
            for(int j = zeroPos[i];j < zeroPos[i + 1];j++) {
                curVal += values[j];
                maxCnt = max(maxCnt, ++sumCnt[curVal]);
            }
            result += maxCnt;
        }
        ll curVal = 0;
        for(int i = 1;i < *zeroPos.begin();i++) {
            curVal += values[i];
            if(curVal == 0) result++; 
        }
        cout << result << endl;
    }
    return 0;
}
