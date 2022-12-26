#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 1e9 + 7;

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
        vector<int> values(n), a(m + 1), b(m + 1), c(m + 1);
        vector<pair<bool, int> > opts;
        vector<vector<int> > ascendingValues, nonAscendingValues;
        {
            vector<int> v1(m + 1, 1), v2(m + 1, 1);
            v1[0] = 0;
            v2[0] = 0;
            ascendingValues.push_back(std::move(v1));
            nonAscendingValues.push_back(std::move(v2));
            bool status = false;
            int statusCnt = 0;
            for(int i = 0;i < n;i++) {
                cin >> values[i];
                if(i == 0) continue;
                if(statusCnt == 0) {
                    status = values[i - 1] < values[i];
                    statusCnt++;
                    continue;
                }
                if((values[i - 1] < values[i]) != status) {
                    opts.push_back(make_pair(status, statusCnt));
                    status = !status;
                    statusCnt = 1;
                } else statusCnt++;
            }
            if(statusCnt != 0) opts.push_back(make_pair(status, statusCnt));
        }
        for(int i = 0;i < static_cast<int>(opts.size());i++) {
            pair<bool, int> val = opts[i];
            if(val.first) {
                if(val.second > ascendingValues.size()) {
                    for(int j = ascendingValues.size();j <= val.second;j++) {
                        vector<int> &last = *ascendingValues.end();
                        vector<int> next(m + 1);
                        int curSum = 0;
                        for(auto v : last) {
                            curSum += v;
                            if(curSum >= MOD) curSum -= MOD;
                        }
                        for(int i = m;i >= 0;i--) {
                            curSum -= last[i];
                            next[i] = curSum;
                        }
                        ascendingValues.push_back(std::move(next));
                    }
                }
                int aSum = (i > 1) ? 0 : 1;
                int bSum = 0;
                if(i != 0) {
                    for(int j = 1;j <= m;j++) {
                        bSum += b[j];
                        if(bSum >= MOD) bSum -= MOD;
                    }
                } else bSum = 1;
                fill(c.begin(), c.end(), 0);
                for(int j = 1;j <= m;j++) {
                    bSum -= b[j];
                    c[j] = (1LL * aSum * b[j]) % MOD;
                }
            }else {
                if(val.second > nonAscendingValues.size()) {
                    for(int j = nonAscendingValues.size(); j <= val.second;j++) {
                        vector<int> &last = *nonAscendingValues.end();
                        vector<int> next(m + 1);
                        int curSum = 0;
                        for(auto v : last) {
                            curSum += v;
                            if(curSum >= MOD) curSum -= MOD;
                        }
                        for(int i = 0;i <= m;i++) {
                            next[i] = curSum;
                            curSum -= last[i];
                        }
                        nonAscendingValues.push_back(std::move(next));
                    }
                }
            }
        }
    }
    return 0;
}
