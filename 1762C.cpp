#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>

template <typename T>
void read_number(T &val) {
    int f = 1;
    val = 0;
    char c;
    while((c = getchar()) != EOF && (c < '0' || c > '9')) if(c == '-') f *= -1;
    while(c != EOF && (c >= '0' && c <= '9')) val = val * 10 + (c - '0'), c = getchar();
    val *= f;
}

template <typename T>
T read_number() {
    T val;
    read_number(val);
    return val;
}

using namespace std;

typedef long long ll;

const int MOD =  998244353;

int main() {
    int T = read_number<int>();
    while(T--) {
        int n = read_number<int>();
        char *s = new char[n + 1];
        scanf("%s", s);
        int prev = s[0] - '0', result = 1, cur = 1;
        for(int i = 1;i < n;i++) {
            int val = s[i] - '0';
            if(val == prev) {
                cur <<= 1;
                if(cur > MOD) cur -= MOD;
            } else {
                cur = 1;
            }
            result += cur;
            if(result > MOD) result -= MOD;
            prev = val;
        }
        printf("%d\n", result);
        delete[] s;
    }
    return 0;
}