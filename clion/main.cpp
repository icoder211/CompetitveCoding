#pragma GCC target ("sse4.2")
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define ln "\n"
#define forn(i,e) for(ll i=0; i<e; i++)
#define forsn(i,s,e) for(ll i=s; i<e; i++)
#define rforn(i,e) for(ll i=e; i>=0; i--)
#define rforsn(i,e,s) for(ll i=e; i>=s; i--)
#define vasort(v)         sort(v.begin(), v.end());
#define vdsort(v)         sort(v.begin(), v.end(),greater<ll>());
#define Nos ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)size(x))
#define     EB              emplace_back
#define     flush           fflush(stdout)
#define out1(x1) cout << x1 << endl
#define out2(x1,x2) cout << x1 << " " << x2 << endl
#define out3(x1,x2,x3) cout << x1 << " " << x2 << " " << x3 << endl
#define out4(x1,x2,x3,x4) cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl
#define all(d) d.begin(), d.end()
#define mp make_pair
#define unordered_set(T) unordered_set<T, custom_hash>
#define unordered_map(T1, T2) unordered_map<T1, T2, custom_hash>

#define in1(x1) cin >> x1
#define in2(x1,x2) cin >> x1 >> x2
#define in3(x1,x2,x3) cin >> x1 >> x2 >> x3
#define in4(x1,x2,x3,x4) cin >> x1 >> x2 >> x3 >> x4

#define arrin(a, n) forn(i, n) cin >> a[i];
#define arrout(a,n) forn(i,n) {cout << a[i] << " ";} cout << ln;



/* ---------------- typedefs ----------------*/
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;


/* ---------------- utility functions ---------------- */
int dr[] = {0,1,-1,0,1,-1,1,-1};
int dc[] = {1,0,0,-1,1,-1,-1,1};
int drr[] = {-2,-1,0,1,2};
int dcc[] = {-2,-1,0,1,2};
bool chk(int a, int b, int n, int m) {
    return 0 <= a && a < n && 0 <= b && b < m;
}

ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}

ll expm(ll n, ll m){
    ll a = 1;
    while (m > 0){
        if(a < 0 or a >= (1e18 + n-1)/n) {
            return -1;
        }
        if (m&1) a = (a * n);
        m /= 2;
        n = (n*n);
    }
    return a;
}

void disp(vi v){
    for(auto u:v)
        cout<<u<<" ";
    cout<< endl;
}
void disp(vll v){
    for(auto u:v)
        cout<<u<<" ";
    cout<<endl;
}

/* custom hash for unordered map */
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);


/* ---------------- start of code ---------------- */

const int N = 301010;

const ll md = 998244353;
ll q,a0,c0;
int c[N], a[N];
int par[N][21] = {0};
int f(int vi) {
    for(int i = 19;i >= 0;i--) {
        if(par[vi][i] == -1) continue;
        if(a[par[vi][i]] <= 0) continue;
        vi = par[vi][i];
    }
    return vi;
}
void go() {
    cin >> q >> a0 >> c0;
    forn(i,N) {
        a[i] = -1;
        c[i] = -1;
    }
    forn(i,20) {
        par[0][i] = -1;
    }
    a[0] = a0;
    c[0] = c0;
    forsn(qq,1,q+1) {
        int tk;cin >> tk;
        if(tk == 1) {
            ll p, ai, ci;in3(p, ai, ci);
            par[qq][0] = p;
            forsn(i, 1, 20) par[qq][i] = par[par[qq][i-1]][i-1];
            c[qq] = ci;
            a[qq] = ai;
        } else {
            ll vi, wi;cin >> vi >> wi;ll wi0 = wi;
            int p = f(vi);
            int p0 = vi;
            vector<int> pars;
            while(p0 != p) {
                pars.pb(p0);
                p0 = par[p0][0];
            }
            pars.pb(p);
//            cout << vi << " ; ";
//            disp(pars);
//            forn(i,qq+1) cout << a[i] << " ";cout<<ln;
//            forn(i,qq+1) cout << c[i] << " ";cout<<ln;
            ll ct = 0;
            for(int i = pars.size()-1;i >= 0;i--) {
                if(wi >= a[pars[i]]) {
                    ct += a[pars[i]] * 1ll* c[pars[i]];
                    wi -= a[pars[i]];
                    a[pars[i]] = 0;
                } else {
                    ct += c[pars[i]] * 1ll * wi;
                    a[pars[i]] -= wi;
                    wi = 0;
                    break;
                }
            }
            cout << wi0 - wi << " ";
            cout << ct << endl;
        }
    }
}

int main() {
    Nos;
//    fflush(stdout);
//    cout<<fixed<<setprecision(11);    cerr<<fixed<<setprecision(10);
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

    ll tt = 1;
//    cin >> tt;
    ll t = tt;
//    auto start  = std::chrono::high_resolution_clock::now();

    while(tt--){
//        cout << "Case #" << t - tt << ": ";
        go();
    }

//    auto stop = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//    cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
}
/* ---------------- end of code ---------------- */