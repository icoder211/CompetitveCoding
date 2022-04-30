
int n;
int t[200005] = {0};
int h;
int d[200005];

void apply(int p, int val) {
    t[p] += val;
    if(p < n) {
        d[p] += val;
    }
}

void push(int p) {
    for(int s = h;s > 0;s--) {
        int i = p >> s;
        if(d[i] != 0) {
            apply(i << 1, d[i]);
            apply(i << 1 | 1, d[i]);
            d[i] = 0;
        }
    }
}

void build(int p) {
    while(p > 1) {
        p >>= 1;
        t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
    }
}

void inc(int l, int r, int val) {
    l += n;
    r += n;
    int l0 = l, r0 = r;
    for(;l < r;l >>= 1, r >>= 1) {
        if(l&1) apply(l++, val);
        if(r&1) apply(--r, val);
    }
    build(l0);
    build(r0-1);
}

int query(int l) {
    l += n;
    push(l);
    int res = t[l];
    return res;
}

template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;

    fenwick(int _n) : n(_n) {
        fenw.assign(n+1, 0);
    }

    void modify(int x, T v) {
        while (x <= n) {
            fenw[x] += v;
            x += (x &-x);
        }
    }

    T get(int x) {
        T v{};
        while (x > 0) {
            v += fenw[x];
            x -= (x & -x);
        }
        return v;
    }

    /*
     * custom set
     * modify(p, 1) to add p; p -> [1, n]
     * ithpos(POS) to get POSth order statistics (POSth smallest element)
     * pos -> [1, n]
     */
    int ithpos(int i) {
        int low = 1, high = n;
        while(low < high) {
            int mid = (low + high) >> 1;
            if(this->get(mid) >= i) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

};


const int N = 2e5 + 33;
int t[2*N];
class segtree{
public:
    int n;

    segtree(int _n) :n(_n) {}
    void build() {
        for(int i = n-1;i > 0;i--) t[i] = max(t[i<<1], t[i<<1|1]);
    }

    void modify(int pos, int val) {
        for(t[pos += n] =  val; pos > 1;pos >>= 1) t[pos >> 1] = max(t[pos], t[pos^1]);
    }

    int query(int l, int r) {
        int res = 0;
        for(l += n, r += n;l < r;l>>=1, r>>=1) {
            if(l&1) res = max(res, t[l++]);
            if(r&1) res=  max(res, t[--r]);
        }
        return res;
    }
};


//segment tree for sums
struct segtree {
    int size;
    vector<long long> sums;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2*size, 0LL);
    }
    void build(vector<int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int)a.size()) {
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, x*2 + 1, lx, m);
        build(a, x*2 + 2, m, rx);
        sums[x] = sums[x*2+1] + sums[x*2+2];
    }
    void build(vector<int> &a) {
        size = a.size();
        build(a, 0, 0, size);
    }

    void set(int i, long long v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, x*2+1, lx, m);
        } else {
            set(i, v, 2*x+2, m, rx);
        }
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void set(int i, long long v) {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if(lx >= rx || l >= rx) return 0;
        if(lx >= l && rx <= r) return sums[x];
        int m = (lx + rx) / 2;
        long long s1 = sum(l, r, 2*x+1, lx, m);
        long long s2 = sum(l, r, 2*x+2, m, rx);
        return s1 + s2;
    }
    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

};

namespace SegmentTree {
    int n;
    ll t[4 * MAXn];
    ll mod[4 * MAXn];
    vll a;


    void pull(int v) {
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    void apply(int v, ll val) {
        t[v] += val;
        mod[v] += val;
    }

    void push(int v) {
        if (mod[v] != 0) {
            apply(2 * v + 1, mod[v]);
            apply(2 * v + 2, mod[v]);
            mod[v] = 0;
        }
    }

    void build(int v, int l, int r) {
        if (l + 1 == r) {
            t[v] = a[l];
        } else {
            int m = (r + l) >> 1;
            build(2 * v + 1, l, m);
            build(2 * v + 2, m, r);
            pull(v);
        }
    }

    void add(int v, int l, int r, int ql, int qr, ll val) {
        if (r <= ql || qr <= l) {
            return;
        } else if (ql <= l && r <= qr) {
            apply(v, val);
        } else {
            push(v);
            int m = (r + l) >> 1;
            add(2 * v + 1, l, m, ql, qr, val);
            add(2 * v + 2, m, r, ql, qr, val);
            pull(v);
        }
    }

    int go_down(int v, int l, int r, ll sums) {
        if (l + 1 == r) {
            return l;
        } else {
            push(v);
            int m = (r + l) >> 1;
            int res = -1;
            if(t[2*v + 1] > sums) {
                res = go_down(2*v+1, l, m, sums);
            } else {
                res = go_down(2*v+2, m, r, sums);
            }
            pull(v);
            return res;
        }
    }

    void init(int n_) {
        n = n_;
        build(0, 0, n);
    }

    void init(const vll &b) {
        n = (int)b.size();
        for(const auto &u: b) a.PB(u);
        build(n, 0, 0);
    }

    void add(int l, int r, ll val) {
        add(0, 0, n, l, r, val);
    }

    void add(int pos, ll val) {
        add(0, 0, n, pos, pos + 1, val);
    }

    int fisrt(ll sums) {
        return go_down(0, 0, n, sums);
    }

    ll getval(int v, int q, int l, int r) {
        if(v == q) {
            return a[v];
        }
        push(v);
        ll res = -1;
        int mid = (l + r) >> 1;
        if(l < mid) {
            res = getval(2*v + 1, l, l, mid);
        }
        else {
            res = getval(2*v + 2, l, mid, r);
        }
        pull(v);
        return res;
    }

    ll getval(int q) {
        q += n;
        return getval(0, q, 0, n);
    }
}
namespace SegmentTree {
    int n;
    ll t[4 * MAXn];
    ll mod[4 * MAXn];
    vll a;


    void pull(int v) {
        t[v] = (t[2 * v + 1] + t[2 * v + 2]);
    }

    void apply(int v, ll val) {
        t[v] += val;
        mod[v] += val;
    }

    void push(int v) {
        if (mod[v] != 0) {
            apply(2 * v + 1, mod[v]);
            apply(2 * v + 2, mod[v]);
            mod[v] = 0;
        }
    }

    void build(int v, int l, int r) {
        if (l + 1 == r) {
            t[v] = a[l];
        } else {
            int m = (r + l) >> 1;
            build(2 * v + 1, l, m);
            build(2 * v + 2, m, r);
            pull(v);
        }
    }

    void add(int v, int l, int r, int ql, int qr, ll val) {
        if (r <= ql || qr <= l) {
            return;
        } else if (ql <= l && r <= qr) {
            apply(v, val);
        } else {
            push(v);
            int m = (r + l) / 2;
            add(2 * v + 1, l, m, ql, qr, val);
            add(2 * v + 2, m, r, ql, qr, val);
            pull(v);
        }
    }

    void init(int n_) {
        n = n_;
        a.assign(n, 0);
        build(0, 0, n);
    }

    void init(const vll &b) {
        n = (int)b.size();
        for(const auto &u: b) a.pb(u);
        build(0, 0, n);
    }

    void add(int l, int r, ll val) {
        add(0, 0, n, l, r, val);
    }

    void add(int pos, ll val) {
        add(0, 0, n, pos, pos + 1, val);
    }

    ll getval(int v, int q, int l, int r) {

        if(l == r-1) {
            assert(l == q);
            return t[v];
        }
        push(v);
        ll res = -1;
        int mid = (l + r) / 2;
        if(q < mid) {
            res = getval(2*v + 1, q, l, mid);
        } else {
            res = getval(2*v + 2, q, mid, r);
        }
        pull(v);
        return res;
    }

    ll getval(int q) {
        return getval(0, q, 0, n);
    }
}
namespace SegmentTree_max {
    ll n;
    pll t[4 * MAXn];
    ll mod[4 * MAXn] = {0};
    vll a;


    void pull(ll v) {
        t[v] = {(t[2*v + 1].F + t[2*v+2].F)%md, (t[2*v+1].S== t[2*v+2].S ? t[2*v + 1].S : -1)};
    }

    void apply(ll v, ll val) {
        t[v] = {max(t[v].F, val), val};
        mod[v] = val;
    }

    void push(ll v) {
        if (mod[v] != 0) {
            apply(2 * v + 1, mod[v]);
            apply(2 * v + 2, mod[v]);
            mod[v] = 0;
        }
    }

    void build(ll v, ll l, ll r) {
        if (l + 1 == r) {
            t[v] = {a[l], a[l]};
        } else {
            int m = (r + l) >> 1;
            build(2 * v + 1, l, m);
            build(2 * v + 2, m, r);
            pull(v);
        }
//        out4(v, t[v], l, r);
    }

    void modify_max(int v, int l, int r, int ql, int qr, ll val) {
        if (r <= ql || qr <= l) {
            return;
        } else if (ql <= l && r <= qr) {
            apply(v, val);
        } else {
            push(v);
            int m = (r + l) >> 1;
            modify_max(2 * v + 1, l, m, ql, qr, val);
            modify_max(2 * v + 2, m, r, ql, qr, val);
            pull(v);
        }
    }
    void modify_max(int l, int r, int val) {
        modify_max(0, 0, n, l, r, val);
    }
    void modify_max(int pos, int val) {
        modify_max(0, 0, n, pos, pos + 1, val);
    }

    void init(int n_) {
        n = n_;
        build(0, 0, n);
    }
    void init(const vi &b) {
        n = (int)b.size();
        a.clear();
        for(const auto &u: b) a.PB(u);
        build(0, 0, n);
    }

    int getval_max(int v, int ql, int qr, int l, int r) {
        if (r <= ql || qr <= l) {
            return 0;
        } else if (ql <= l && r <= qr) {
            return t[v].F;
        }
        push(v);
        int res = 0;
        int mid = (l + r) >> 1;
        res = max(res, getval_max(2*v + 1, ql, qr, l, mid));
        res = max(res, getval_max(2*v + 2, ql, qr, mid, r));
        pull(v);
        return res;
    }
    // ql, qr analogous to modify_max(). 0-indexed.
    ll getval_max(int ql, int qr) {
        return getval_max(0, ql, qr, 0, n);
    }
}
