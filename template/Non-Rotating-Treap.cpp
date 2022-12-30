#include <algorithm>

using namespace std;

namespace NRTreap {
    const int MAXN = 2e5 + 10;
    typedef int T;

    int ch[MAXN][2], pri[MAXN], siz[MAXN], nodeSiz = 0;
    T val[MAXN];

    void init() {
        nodeSiz = 0;
        srand(12345);
    }

    int newNode(T value) {
        int now = ++nodeSiz;
        ch[now][0] = ch[now][1] = 0;
        pri[now] = rand();
        siz[now] = 1;
        val[now] = value;
        return now;
    }

    void maintain(int now) {
        siz[now] = siz[ch[now][0]] + siz[ch[now][1]] + 1;
    }

    void pushDown(int now) {

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

    int insert(int now, T value) {
        pair<int, int> tmpRes = splitByVal(now, value);
        int node = newNode(value);
        return merge(tmpRes.first, merge(node, tmpRes.second));
    }

    int insertByPos(int now, T value, int pos) {
        pair<int, int> tmpRes = splitBySize(now, pos);
        int node = newNode(value);
        return merge(tmpRes.first, merge(node, tmpRes.second));
    }

    int remove(int now, T value) {
        pair<int, int> tmpRes = splitByVal(now, value);
        // TODO: node recycle?
        return merge(splitBySize(tmpRes.first, siz[tmpRes.first] - 1).first, tmpRes.second);
    }

    int removeByPos(int now, int pos) {
        pair<int, int> tmpRes = splitBySize(now, pos);
        // TODO: node recycle?
        return merge(splitBySize(tmpRes.first, siz[tmpRes.first] - 1).first, tmpRes.second);
    }
};
