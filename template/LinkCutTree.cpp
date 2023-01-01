#include <algorithm>

using namespace std;


namespace LCT {
    #define LHS(x) ch[x][0]
    #define RHS(x) ch[x][1]
    #define GETCH(x) (ch[fa[x]][1] == x)
    const int MAXN = 2e5 + 10;

    int ch[MAXN][2], fa[MAXN], rev[MAXN];

    void maintain(int x) {
        if(!x) return;
        // maintain the data on node
    }

    void clear(int x) {
        ch[x][0] = ch[x][1] = fa[x] = rev[x] = 0;
    }

    int isRoot(int x) {
        return LHS(fa[x]) != x && RHS(fa[x]) != x;
    }

    void pushDown(int x) {
        if(rev[x]) {
            if(LHS(x)) {
                swap(LHS(LHS(x)), RHS(LHS(x)));
                rev[LHS(x)] ^= 1;
            }
            if(RHS(x)) {
                swap(LHS(RHS(x)), RHS(RHS(x)));
                rev[RHS(x)] ^= 1;
            }
            rev[x] = false;
        }
    }

    void update(int x) {
        if(!isRoot(x)) update(fa[x]);
        pushDown(x);
    }

    void rotate(int x) {
        int y = fa[x], z = fa[y], chx = GETCH(x), chy = GETCH(y);
        fa[x] = z;
        if(!isRoot(y)) ch[z][chy] = x;
        ch[y][chx] = ch[x][chx ^ 1];
        fa[ch[x][chx ^ 1]] = y;
        ch[x][chx ^ 1] = y;
        fa[y] = x;
        maintain(y);
        maintain(x);
        maintain(z);
    }

    void splay(int x) {
        update(x);
        for(int f; f = fa[x], !isRoot(x); rotate(x)) if(!isRoot(f)) rotate(GETCH(x) == GETCH(f) ? f : x);
    }

    int access(int x) {
        int f = 0;
        for(; x; f = x, x = fa[x]) splay(x), ch[x][1] = f, maintain(x);
        return f;
    }
    void makeRoot(int x) {
        access(x);
        splay(x);
        swap(LHS(x), RHS(x));
        rev[x] ^= 1;
    }

    int find(int x) {
        access(x);
        splay(x);
        while(LHS(x)) x = LHS(x);
        splay(x);
        return x;
    }

    void link(int x, int y) {
        makeRoot(x);
        access(y);
        splay(y);
        int tmp = y;
        while(LHS(tmp)) tmp = LHS(tmp);
        if(tmp == x) return;
        fa[x] = y;
    }

    void cut(int x, int y) {
        makeRoot(x);
        access(y);
        splay(y);
        if(fa[x] == y && LHS(y) == x && RHS(x) == 0) LHS(y) = fa[x] = 0;
        maintain(y);
    }

    #undef LHS
    #undef RHS
    #undef GETCH
};
