#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long int ll;
typedef long double ld;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define Nos                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fo(i,n) for(ll i=0;i<n;i++)
#define forn(i,n) for(ll i=0;i<n;i++)
#define rfo(i,n) for(ll i = n;i >= 0;i--)
#define rfosn(i, s, n) for(ll i = n; i >= s; i--)
#define PI 3.141592654
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define pb push_back
#define mp make_pair
#define fosn(i, s, n) for(int i = s;i < n;i ++)
 
#define vb vector<bool>
#define vvb vector<vb>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define ln '\n'
#define pii pair<int,int>
#define vpi vector<pii>
// #define unordered_set(T) unordered_set<T, custom_hash>
// #define unordered_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define f first
#define se second
#define out2(a1,a2) cout << a1 << " " << a2 << endl  

const ll md = 1e9 + 7; //998244353 ;
//ll hash_prime = 31;
// const ll md = 998244353; // 1e9+7;
long long exp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res%m;
}

ll ncr(ll n, ll k) {
    if(n < k) return 0;
    ll res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        {res *= i; res %= md;}
    for (int i = 2; i <= k; ++i)
        {res *= exp(i, md-2, md); res %= md;}
    return res;
}

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
const int N = 3e5;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, d;
ll m;
ll a[N], b[N];
ll dp[401][401][2];
void go1() {
    cin >> n >> d;
    // assert(n <= 40 and d <= 10);
    // assert(d == 2);
    fo(i,n) cin >> a[i];
    m = 1;
    b[0] = a[0];
    fosn(i,1,n) {
        if(a[i] != a[i-1]) {
            b[m] = a[i];
            m++;
        }
    }
    n = m;
    fo(i,n) a[i] = b[i];

    fo(i,n+1)fo(j,n+1)fo(k,2)dp[i][j][k] = 1e18;
    dp[0][n][0] = min(a[0], d - a[0]);
    dp[0][n][1] = min(a[n-1], d - a[n-1]);

    rfo(len, n-1) {
        fo(i,n) {
            int l = i;
            int r = i + len;
            if(r > n) continue;
            if(l > 0) {
                dp[l][r][0] = min(dp[l][r][0], dp[l-1][r][0] + min(abs(a[l]- a[l-1]), min(a[l], a[l-1]) + d - max(a[l], a[l-1])));
                dp[l][r][1] = min(dp[l][r][1], dp[l-1][r][0] + min(abs(a[r-1]- a[l-1]), min(a[r-1], a[l-1]) + d - max(a[r-1], a[l-1])));
            }
            if(r < n) {
                dp[l][r][0] = min(dp[l][r][0], dp[l][r+1][1] + min(abs(a[l]- a[r]), min(a[l], a[r]) + d - max(a[l], a[r])));
                dp[l][r][1] = min(dp[l][r][1], dp[l][r+1][1] + min(abs(a[r-1]- a[r]), min(a[r-1], a[r]) + d - max(a[r-1], a[r])));
            }
            // cout << l << " " << r << " " << dp[l][r][0] << " " << dp[l][r][1] << ln;
        }
    }
    ll ans = 1e18 ;
    fo(i,n) {
        // cout << dp[i][i+1][0] << " " << dp[i][i+1][1] << ln;
        ans = min(ans, dp[i][i+1][0]);
        ans = min(ans, dp[i][i+1][1]);
    }
    cout << ans << ln;

}
int main(){   

    Nos;

    // freopen("a.txt", "r", stdin);
    cout << fixed << setprecision(25);

    int t=1;
    cin>>t;
    int t_=t;

    while(t--){
        cout << "Case #"<<t_-t<<": ";
        go1();
    }
    return 0;
}