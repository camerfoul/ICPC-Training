#include <algorithm>
#include <cstdio>
#include <iomanip>

using namespace std;

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

const int MAXN = 2e5 + 10;
const int MAX_LOG_N = 18;

int p[MAXN], v[MAXN], dep[MAXN], p2[MAXN][MAX_LOG_N + 1], maxLen[MAXN], maxLen2[MAXN][MAX_LOG_N + 1], minDep[MAXN];

struct Graph {
    struct Edge {
        int v, nxt;
    } edges[2 * MAXN];
    int head[MAXN], siz;

    void init(int n) {
        for(int i = 0;i <= n;i++) {
            head[i] = -1;
        }
        siz = 0;
    }
    
    void add(int u, int v) {
        edges[siz].v = v;
        edges[siz].nxt = head[u];
        head[u] = siz++;
    }
} g;

void dfs(int now) {
    dep[now] = dep[p[now]] + 1;
    p2[now][0] = p[now];
    for(int i = 1;i <= MAX_LOG_N;i++) p2[now][i] = p2[p2[now][i - 1]][i - 1];
    if(p[now] == 0) maxLen[now] = 1;
    else if(p[p[now]] == 0 || v[now] - v[p[now]] == v[p[now]] - v[p[p[now]]]) maxLen[now] = maxLen[p[now]] + 1;
    else maxLen[now] = 2;
    maxLen2[now][0] = maxLen[now];
    for(int i = 1;i <= MAX_LOG_N;i++) maxLen2[now][i] = max(maxLen2[now][i - 1], maxLen2[p2[now][i - 1]][i - 1]);
    if(p[now] == 0) minDep[now] = now;
    else minDep[now] = maxLen[now] == 2 ? p[now] : minDep[p[now]];
    for(int i = g.head[now];i != -1;i = g.edges[i].nxt) {
        int v = g.edges[i].v;
        if(dep[v] == 0) {
            p[v] = now;
            dfs(v);
        }
    }
}

int getLCA(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = MAX_LOG_N;i >= 0;i--) {
        int nxt = p2[u][i];
        if(dep[nxt] < dep[v]) continue;
        u = nxt;
    }
    if(u == v) return u;
    for(int i = MAX_LOG_N;i >= 0;i--) {
        int nxt1 = p2[u][i], nxt2 = p2[v][i];
        if(nxt1 == nxt2) continue;
        u = nxt1;
        v = nxt2;
    }
    return p[u];
}

int main() {
    int N = read_number<int>();
    g.init(N);
    for(int i = 1;i <= N;i++) {
        read_number(v[i]);
    }
    for(int i = 0;i < N - 1;i++) {
        int u = read_number<int>(), v = read_number<int>();
        g.add(u, v);
        g.add(v, u);
    }
    dfs(1);
    int Q = read_number<int>();
    for(int i = 1;i <= Q;i++) {
        int X = read_number<int>(), Y = read_number<int>();
        int lca = getLCA(X, Y), result = 1, sA = -1, sB = -1;
        if(X != lca) {
            int cur = X;
            for(int i = MAX_LOG_N;i >= 0;i--) {
                int nxt = p2[cur][i];
                if(dep[minDep[nxt]] <= dep[lca]) continue;
                result = max(result, maxLen2[cur][i]);
                cur = nxt;
            }
            if(dep[minDep[cur]] > dep[lca]) result = max(result, dep[cur] - dep[minDep[cur]] + 1), cur = p[cur];
            result = max(result, dep[cur] - dep[lca] + 1);
            sA = cur;
        }
        if(Y != lca) {
            int cur = Y;
            for(int i = MAX_LOG_N;i >= 0;i--) {
                int nxt = p2[cur][i];
                if(dep[minDep[nxt]] <= dep[lca]) continue;
                result = max(result, maxLen2[cur][i]);
                cur = nxt;
            }
            if(dep[minDep[cur]] > dep[lca]) result = max(result, dep[cur] - dep[minDep[cur]] + 1), cur = p[cur];
            result = max(result, dep[cur] - dep[lca] + 1);
            sB = cur;
        }
        if(sA != -1 && sB != -1) {
            int deltaA = v[sA] - v[p[sA]], deltaB = v[p[sB]] - v[sB];
            if(deltaA == deltaB) result = max(result, (dep[sA] - dep[lca] + 1) + (dep[sB] - dep[lca] + 1) - 1);
        }
        printf("%d\n", result);
    }



    return 0;
}