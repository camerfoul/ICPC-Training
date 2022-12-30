#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

vector<vector<int> > rowMax, colMax, matrixMax;

bool check(int l, vector<vector<int>> &values, int n, int m) {
    int maxVal = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            bool exist = values[i][j] >= l;
            {
                int prev = (i == 0) ? 0 : rowMax[i - 1][j];
                rowMax[i][j] = exist ? prev + 1 : 0;
            }
            {
                int prev = (j == 0) ? 0 : colMax[i][j - 1];
                colMax[i][j] = exist ? prev + 1 : 0;
            }
            if(exist) {
                int prevMatrix = (i == 0 || j == 0) ? 0 : matrixMax[i - 1][j - 1];
                matrixMax[i][j] = min(prevMatrix + 1, min(rowMax[i][j], colMax[i][j]));
            } else {
                matrixMax[i][j] = 0;
            }
            maxVal = max(maxVal, matrixMax[i][j]);
        }
    }
    return maxVal >= l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int maxVal = 0;
        vector<vector<int>> values;
        for (int i = 0; i < n; i++) {
            vector<int> tmpValues(m);
            for (int j = 0; j < m; j++) {
                int value;
                cin >> value;
                maxVal = max(maxVal, value);
                tmpValues[j] = value;
            }
            values.push_back(move(tmpValues));
        }
        rowMax.clear();
        colMax.clear();
        matrixMax.clear();
        for(int i = 0;i < n;i++) {
            rowMax.push_back(move(vector<int>(m)));
            colMax.push_back(move(vector<int>(m)));
            matrixMax.push_back(move(vector<int>(m)));
        }
        int left = 1, right = maxVal;
        int result = 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(check(mid, values, n, m)) {
                result = max(result, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << result << endl;
    }

    return 0;
}
