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

const int N = 201010;

const ll md = 998244353;
pair<int,int> a[4];
void go() {
    forn(i,4) {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a,a+4);
    if(a[0].S + a[1].S <= 1 or a[0].S + a[1].S >= 5) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

}

int main() {
    Nos;
//    fflush(stdout);
    cout<<fixed<<setprecision(11);    cerr<<fixed<<setprecision(10);
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

    ll tt = 1;
    cin >> tt;
    ll t = tt;
    auto start  = std::chrono::high_resolution_clock::now();

    while(tt--){
//        cout << "Case #" << t - tt << ": ";
        go();
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
}
/* ---------------- end of code ---------------- */