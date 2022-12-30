#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

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

#include <algorithm>

using namespace std;

namespace NRTreap {
    const int MAXN = 2e5 + 10;
    typedef int T;

    int ch[MAXN][2], pri[MAXN], siz[MAXN], nodeSiz = 0;
    T val[MAXN], ans[MAXN], ansMark[MAXN];
    T valTag[MAXN], ansTag[MAXN];

    void init() {
        nodeSiz = 0;
        srand(12345);
    }

    int newNode(T value, T answerMark) {
        int now = ++nodeSiz;
        ch[now][0] = ch[now][1] = 0;
        pri[now] = rand();
        siz[now] = 1;
        val[now] = value;
        ans[now] = 0;
        ansMark[now] = answerMark;
        valTag[now] = 0;
        ansTag[now] = 0;
        return now;
    }

    void maintain(int now) {
        siz[now] = siz[ch[now][0]] + siz[ch[now][1]] + 1;
    }

    void pushDown(int now) {
        if(valTag[now]) {
            if(ch[now][0]) val[ch[now][0]] += valTag[now], valTag[ch[now][0]] += valTag[now];
            if(ch[now][1]) val[ch[now][1]] += valTag[now], valTag[ch[now][1]] += valTag[now];
            valTag[now] = 0;
        }
        if(ansTag[now]) {
            if(ch[now][0]) ans[ch[now][0]] += ansTag[now], ansTag[ch[now][0]] += ansTag[now];
            if(ch[now][1]) ans[ch[now][1]] += ansTag[now], ansTag[ch[now][1]] += ansTag[now];
            ansTag[now] = 0;
        }
    }

    int merge(int a, int b) {
        if(!a) return b;
        if(!b) return a;
        if(pri[a] < pri[b]) {
            pushDown(a);
            ch[a][1] = merge(ch[a][1], b);
            maintain(a);
            return a;
        } else {
            pushDown(b);
            ch[b][0] = merge(a, ch[b][0]);
            maintain(b);
            return b;
        }
    }

    pair<int, int> splitBySize(int now, int lSiz) {
        if(!now) return {0, 0};
        if(lSiz == siz[now]) return {now, 0};
        pushDown(now);
        if(lSiz < siz[ch[now][0]] + 1) {
            pair<int, int> tmpRes = splitBySize(ch[now][0], lSiz);
            ch[now][0] = tmpRes.second;
            maintain(now);
            return {tmpRes.first, now};
        } else {
            pair<int, int> tmpRes = splitBySize(ch[now][1], lSiz - siz[ch[now][0]] - 1);
            ch[now][1] = tmpRes.first;
            maintain(now);
            return {now, tmpRes.second};
        }
    }

    // <=
    pair<int, int> splitByVal(int now, T value) {
        if(!now) return {0, 0};
        pushDown(now);
        if(val[now] > value) {
            pair<int, int> tmpRes = splitByVal(ch[now][0], value);
            ch[now][0] = tmpRes.second;
            maintain(now);
            return {tmpRes.first, now};
        } else {
            pair<int, int> tmpRes = splitByVal(ch[now][1], value);
            ch[now][1] = tmpRes.first;
            maintain(now);
            return {now, tmpRes.second};
        }
    }

    int insert(int now, int newNode) {
        pair<int, int> tmpRes = splitByVal(now, val[newNode]);
        return merge(tmpRes.first, merge(newNode, tmpRes.second));
    }

    int insert(int now, T value, T answerMark) {
        pair<int, int> tmpRes = splitByVal(now, value);
        int node = newNode(value, answerMark);
        return merge(tmpRes.first, merge(node, tmpRes.second));
    }

    void dfs(int now, T v, int &newRoot) {
        if(!now) return;
        pushDown(now);
        dfs(ch[now][0], v, newRoot);
        dfs(ch[now][1], v, newRoot);
        ch[now][0] = ch[now][1] = 0;
        val[now] -= v;
        ans[now]++;
        newRoot = insert(newRoot, now);
    }

    void getAns(int now, vector<int> &result) {
        if(!now) return;
        pushDown(now);
        getAns(ch[now][0], result);
        getAns(ch[now][1], result);
        result[ansMark[now]] = ans[now];
    }
};

using namespace NRTreap;

int main() {
    int n = read_number<int>();
    vector<pair<int, int> > values(n);
    for(int i = 0;i < n;i++) {
        int c = read_number<int>();
        int q = read_number<int>();
        values[i] = {-q, c};
    }
    sort(values.begin(), values.end());
    int k = read_number<int>(), root = -1;
    for(int i = 0;i < k;i++) {
        int d = read_number<int>();
        if(root == -1) {
            root = newNode(d, i);
            continue;
        }
        root = insert(root, d, i);
    }
    for(int i = 0;i < n;i++) {
        int cost = values[i].second;
        pair<int, int> first = splitByVal(root, cost - 1);
        pair<int, int> second = splitByVal(first.second, 2 * cost - 1);
        dfs(second.first, cost, first.first);
        val[second.second] -= cost;
        valTag[second.second] -= cost;
        ans[second.second]++;
        ansTag[second.second]++;
        root = merge(first.first, second.second);
    }
    vector<int> result(k);
    getAns(root, result);
    for(auto v : result) printf("%d ", v);
    printf("\n");
    return 0;
}