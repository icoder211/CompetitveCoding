#include <bits/stdc++.h>

using namespace std;

template <uint32_t Modulus>
class ModularInt {
    using M = ModularInt;

   public:
    static_assert(int(Modulus) >= 1, "Modulus must be in the range [1, 2^31)");
    static constexpr int modulus() { return Modulus; }
    static M raw(uint32_t v) { return *reinterpret_cast<M*>(&v); }
    ModularInt() : v_(0) {}
    ModularInt(int64_t v) : v_((v %= Modulus) < 0 ? v + Modulus : v) {}
    template <class T>
    explicit operator T() const {
        return v_;
    }
    M& operator++() { return v_ = ++v_ == Modulus ? 0 : v_, *this; }
    M& operator--() { return --(v_ ? v_ : v_ = Modulus), *this; }
    M& operator*=(M o) { return v_ = uint64_t(v_) * o.v_ % Modulus, *this; }
    M& operator/=(M o) {
        auto [inv, gcd] = extgcd(o.v_, Modulus);
        assert(gcd == 1);
        return *this *= inv;
    }
    M& operator+=(M o) {
        return v_ = int(v_ += o.v_ - Modulus) < 0 ? v_ + Modulus : v_, *this;
    }
    M& operator-=(M o) {
        return v_ = int(v_ -= o.v_) < 0 ? v_ + Modulus : v_, *this;
    }
    friend M operator++(M& a, int) { return exchange(a, ++M(a)); }
    friend M operator--(M& a, int) { return exchange(a, --M(a)); }
    friend M operator+(M a) { return a; }
    friend M operator-(M a) { return a.v_ = a.v_ ? Modulus - a.v_ : 0, a; }
    friend M operator*(M a, M b) { return a *= b; }
    friend M operator/(M a, M b) { return a /= b; }
    friend M operator+(M a, M b) { return a += b; }
    friend M operator-(M a, M b) { return a -= b; }
    friend istream& operator>>(istream& is, M& x) {
        int64_t v;
        return is >> v, x = v, is;
    }
    friend ostream& operator<<(ostream& os, M x) { return os << x.v_; }
    friend bool operator==(M a, M b) { return a.v_ == b.v_; }
    friend bool operator!=(M a, M b) { return a.v_ != b.v_; }

   private:
    static pair<int, int> extgcd(int a, int b) {
        array<int, 2> x{1, 0};
        while (b) swap(x[0] -= a / b * x[1], x[1]), swap(a %= b, b);
        return {x[0], a};
    }
    uint32_t v_;
};

// using mint = ModularInt<int(1e9 + 7)>;

template <typename T>
struct Fenwick {
    int n;
    vector<T> t;
    Fenwick(int n) : n(n), t(n + 1) {}
    T query(int i) {
        T s = 0;
        while (i) s += t[i], i -= i & (-i);
        return s;
    }
    T query(int l, int r) { return query(r) - query(l - 1); }
    void update(int i, T v) {
        while (i <= n) t[i] += v, i += i & (-i);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;k++;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> b = a;
    sort(begin(b), end(b));
    b.erase(unique(begin(b), end(b)), end(b));
    for (auto& x : a) x = lower_bound(begin(b), end(b), x) - begin(b) + 1;
    vector<long long> ans(n, 1);
    for (int i = 1; i < k; ++i) {
        Fenwick<long long> f(n);
        for (int i = 0; i < n; ++i) {
            f.update(a[i], ans[i]);
            ans[i] = f.query(a[i] - 1);
        }
    }
    cout << accumulate(begin(ans), end(ans), 0) << '\n';
    return 0;
}