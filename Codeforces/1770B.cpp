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
        int n, k;
        cin >> n >> k;
        int upperPos = n, lowerPos = 1;
        while(upperPos >= lowerPos) {
            for(int i = 0;i < k - 1;i++) {
                cout << upperPos-- << " ";
                if(upperPos < lowerPos) break;
            }
            if(upperPos < lowerPos) break;
            cout << lowerPos++ << " ";
            if(upperPos < lowerPos) break;
        }
        cout << endl;
    }
    return 0;
}
