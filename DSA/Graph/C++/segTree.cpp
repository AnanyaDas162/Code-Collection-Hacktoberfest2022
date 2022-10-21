#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

struct ST {
    int t[4 * N], *a;
    static const int inf = 1e9;
    ST(int arr[]) {
        memset(t, 0, sizeof t);
        a = arr;
    }
    void build(int n, int b, int e) {
        if (b == e) {
            t[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = max(t[l], t[r]);
    }
    void upd(int n, int b, int e, int i, int x) {
        if (b > i || e < i) return;
        if (b == e && b == i) {
            t[n] = x;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n] = max(t[l], t[r]);
    }
    int query(int n, int b, int e, int i, int j) {
        if (b > j || e < i) return -inf;
        if (b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        int L = query(l, b, mid, i, j);
        int R = query(r, mid + 1, e, i, j);
        return max(L, R);
    }
};

int main() {
    
}
