#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int> > counts;
    vector<vector<string> > pics(k + 1, vector<string>(n));
    for(int i = 0;i < k + 1;i++) {
        vector<string> &pic = pics[i];
        for(int j = 0;j < n;j++) {
            cin >> pic[j];
        }
        int cnt = 0;
        for(int j = 1;j < n - 1;j++) {
            for(int l = 1;l < m - 1;l++) {
                if(pic[j][l] != pic[j - 1][l] && pic[j][l] != pic[j + 1][l] && pic[j][l] != pic[j][l - 1] && pic[j][l] != pic[j][l + 1]) cnt++;
            }
        }
        counts.push_back(make_pair(cnt, i));
    }
    sort(counts.begin(), counts.end());
    cout << counts[k].second + 1 << endl;
    vector<pair<int, pair<int, int> > > results;
    int optCnt = 0;
    for(int i = k - 1;i >= 0;i--) {
        vector<string> &a = pics[counts[i + 1].second];
        vector<string> &b = pics[counts[i].second];
        for(int j = 0;j < n;j++) {
            for(int l = 0;l < m;l++) {
                if(a[j][l] != b[j][l]) {
                    optCnt++;
                    results.push_back(make_pair(1, make_pair(j + 1, l + 1)));
                }
            }
        }
        optCnt++;
        results.push_back(make_pair(2, make_pair(counts[i].second + 1, -1)));
    }
    cout << optCnt << endl;
    for(auto v : results) {
        if(v.first == 1) {
            cout << 1 << " " << v.second.first << " " << v.second.second << endl;
        } else {
            cout << 2 << " " << v.second.first << endl;
        }
    }
    return 0;
}
