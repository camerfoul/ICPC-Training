// TODO
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

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> cnt(n + 1), vA(n), vB(n), posA(n + 1, -1), posB(n + 1, -1);
        vector<vector<int> > g(n + 1);
        for(int i = 0;i < n;i++) {
            cin >> vA[i];
            cnt[vA[i]]++;
            posA[vA[i]] = i;
        }
        for(int i = 0;i < n;i++) {
            cin >> vB[i];
            cnt[vB[i]]++;
            posB[vB[i]] = i;
        }
        vector<bool> visited(n);
        priority_queue<int> ones;
        set<int> removed;
        for(int i = 1;i <= n;i++) if(cnt[i] == 1) ones.push(i);
        while(!ones.empty()) {
            int v = ones.top();
            ones.pop();
            visited[v] = true;

            if(posA[v] != -1) {
            } else {

            }
        }
    }
    return 0;
}
