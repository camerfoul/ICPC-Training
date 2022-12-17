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
        string s;
        cin >> s;
        char prev = '\0';
        int prevCnt = 0, oneCnt = 0, zeroCnt = 0;
        long long result = 0;
        for(char c : s) {
            if(c == '1') oneCnt++; else zeroCnt++;
            if(prev == c) {
                prevCnt++;
                continue;
            }
            result = max(result, prevCnt * 1LL * prevCnt);
            prev = c;
            prevCnt = 1;
        }
        result = max(result, prevCnt * 1LL * prevCnt);
        result = max(result, zeroCnt * 1LL * oneCnt);
        cout << result << endl;
    }
    return 0;
}