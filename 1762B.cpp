#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

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

const ll MAX_V = 1e9;

int main() {
    int T = read_number<int>();
    while(T--) {
        int n = read_number<int>();
        printf("%d\n", n);
        for(int i = 0;i < n;i++) {
            ll val = read_number<ll>();
            printf("%d %lld\n", i + 1, MAX_V - val);
        }
    }
    return 0;
}