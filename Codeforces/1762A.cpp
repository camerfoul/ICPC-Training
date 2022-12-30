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

int main() {
    int T = read_number<int>();
    while(T--) {
        int n = read_number<int>();
        int result = static_cast<int>(1e6), sum = 0;
        for(int i = 0;i < n;i++) {
            int val = read_number<int>();
            sum += val;
            int flag = val & 1;
            int cur = val, tmpRes = 0;
            while((cur & 1) == flag) cur >>= 1, tmpRes++;
            result = min(result, tmpRes);
        }
        if(sum & 1) printf("%d\n", result);
        else printf("0\n");
    }
    return 0;
}