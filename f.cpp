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
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)size(x))
#define     EB              emplace_back
#define     flush           fflush(stdout)
#define out1(x1) cout << x1 << ln
#define out2(x1,x2) cout << x1 << " " << x2 << endl
#define out3(x1,x2,x3) cout << x1 << " " << x2 << " " << x3 << endl
#define out4(x1,x2,x3,x4) cout << x1 << " " << x2 << " " << x3 << " " << x4 << ln
#define all(d) d.begin(), d.end()
#define unordered_set(T) unordered_set<T, custom_hash>
#define unordered_map(T1, T2) unordered_map<T1, T2, custom_hash>

#define in1(x1) cin >> x1
#define in2(x1,x2) cin >> x1 >> x2
#define in3(x1,x2,x3) cin >> x1 >> x2 >> x3
#define in4(x1,x2,x3,x4) cin >> x1 >> x2 >> x3 >> x4

#define arrin(a, n) forn(i, n) cin >> a[i];
#define arrout(a,n) forn(i,n) {cout << a[i] << " ";} cout << ln;


/* ---------------- IO ----------------*/

namespace IO
{
    const int BUFFER_SIZE = 1 << 15;
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;
    char number_buffer[100];
    uint8_t lookup[100];
    void _update_input_buffer()
    {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
        if (input_len == 0)
            input_buffer[0] = EOF;
    }
    inline char next_char(bool advance = true)
    {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template <typename T>
    inline void read_int(T &number)
    {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do
        {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template <typename T, typename... Args>
    inline void read_int(T &number, Args &... args)
    {
        read_int(number);
        read_int(args...);
    }

    void _flush_output()
    {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c)
    {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template <typename T>
    inline void write_int(T number, char after = '\0')
    {
        if (number < 0)
        {
            write_char('-');
            number = -number;
        }
        int length = 0;
        while (number >= 10)
        {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }
        if (number != 0 || length == 0)
            write_char(number + '0');
        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);
        if (after)
            write_char(after);
    }
    void IOinit()
    {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);
        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
} // namespace IO
using namespace IO;
/* DEBUG */
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
    vector<string> __attribute__ ((unused)) args,
    __attribute__ ((unused)) int idx,
    __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
/* ---------------- typedefs ----------------*/
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
/* ---------------- constants ---------------- */
const ll MAXn=1000,MAXlg=__lg(MAXn)+2;
const ll mod=1e9 + 7;
const ll INF=ll(1e15);
const ll PI = acosl(-1.0);

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
    cout<<"\n";
}
void disp(vll v){
    for(auto u:v)
        cout<<u<<" ";
    cout<<endl;
}

int getSqr(int x){
    if(x < 0)
        return -1;
    int l = sqrt(x);
    for (int i = -2; i <= 2; ++i)
        if (l + i >= 0 && (l + i) * (l + i) == x)
            return l;
    return -1;
}

const int NPRR = 1e7;
vi lp;
vector<int> prr;
void prfac(int n = NPRR){
    assert(n <= NPRR);
    lp.assign(n+1, 0);
    int i;
    for (i = 2;i <= n;++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            prr.push_back(i);
        }
        for (int u: prr) {
            if(i * u > n || u > lp[i]) break;
            lp[i * u] = u;
        }
    }
}
ll fact[300001],infac[300001];
ll fe(ll a,ll b){
    ll temp=a;
    ll ans=1ll;
    while(b){
        if(b&1){
            ans*=(ll)temp;
            ans%=mod;
        }
        b/=2ll;
        temp=temp*(ll)temp;
        temp%=mod;
    }
    ans += mod;
    ans %= mod;
    return ans%mod;
}
ll mi(ll a){
    return(fe(a,mod-2));
}

void fac(){
    fact[0]=1;
    infac[0]=1;
    forsn(i,1,2009){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
        infac[i]=mi(fact[i]);
        infac[i]%=mod;
    }
}
ll ncr(ll a,ll b){
    if(a<b || a<=0)return 0;
    ll ans=fact[a];
    ans*=infac[b];
    ans%=mod;
    ans*=infac[a-b];
    ans%=mod;
    return ans;
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


inline void read(int &x)
{
    scanf("%d", &x);
}

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);


/* ---------------- start of code ---------------- */

ll a[500005], b[500005], c[100005], d[100005];
vll rl[1505], rb[1505], cl[1505], cb[1505];
void merge(vll &a, vll &b, vll &res, vll &bol) {
    sort(all(a));

    sort(all(b));
    int  i = 0 , j = 0;
//    vll res, bol;
    while(i < a.size() and j < b.size()) {
        if(a[i] > b[j]) {
            res.pb(b[j]);
            bol.pb(0);
            j++;
        } else {
            res.pb(a[i]);
            bol.pb(1);
            i++;
        }
    }
    while(i < a.size()) {
        res.pb(a[i]);
        bol.pb(1);
        i++;
    }
    while(j < b.size()) {
        res.pb(b[j]);
        bol.pb(0);
        j++;
    }
}
vector<vi> ans;
void go() {
    int h,w;cin >> h>>w;
    int n, m;in2(n, m);
    ans.assign(h, vi(w, 0));
    forn(i, n) {
        cin >> a[i] >> b[i];a[i]--;b[i]--;
        rl[a[i]].pb(b[i]);
        cl[b[i]].pb(a[i]);
    }forn(i,m) {
        cin >> c[i] >> d[i];c[i]--;d[i]--;
        rb[c[i]].pb(d[i]);
        cb[d[i]].pb(c[i]);
    }

    forn(i, h) {
        vll res, bol;
        if(rl[i].empty()) continue;
        merge (rl[i], rb[i], res, bol);
        assert(bol.size() == res.size());
//        disp(res);
//        disp(bol);
        if(bol.empty()) continue;
        if(bol[0] == 1) {
            forn(j, res[0]) ans[i][j] = 1;
        }
        for(int k = 0;k < res.size() - 1; k++) {
            assert(res[k] < w and res[k] >= 0);
            if(bol[k] == 1 || bol[k+1] == 1) {
                forsn(j, res[k]+1, res[k+1]) ans[i][j] = 1;
                if(bol[k]==1) ans[i][res[k]] = 1;

                if(bol[k+1] == 1) ans[i][res[k+1]] = 1;
            }
        }
        if(bol.back() == 1) {

            forsn(j, res[bol.size() - 1], w) ans[i][j] = 1;
        }
    }
    forn(i,w) {
        vll res,bol;
        merge(cl[i], cb[i], res, bol);
        assert(bol.size() == res.size());

        if(bol.empty()) continue;

        if(bol[0] == 1) {
            forn(j, res[0]) ans[j][i] = 1;
        }
        for(int k = 0;k < res.size() - 1; k++) {
            if(bol[k] == 1 || bol[k+1] == 1) {
                forsn(j, res[k]+1, res[k+1]) ans[j][i] = 1;
                if(bol[k]==1) ans[res[k]][i] = 1;
                if(bol[k+1] == 1) ans[res[k+1]][i] = 1;
            }
        }
        if(bol.back() == 1) {
            forsn(j, res[bol.size() - 1], h) ans[j][i] = 1;
        }
    }
    ll anss = 0;
    forn(i, h) {
//        disp(ans[i]);
        forn(j, w) {

            assert(ans[i][j] <= 1 and ans[i][j]>=0);
            anss += ans[i][j];
        }
    }
    cout << anss << ln;
}



int main(){

    fio;
    fflush(stdout);
    cout<<fixed<<setprecision(11);
    cerr<<fixed<<setprecision(10);

    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

    ll tt = 1;

/*

    cin >> tt;
    ll t = tt;

    //*/

    auto start  = std::chrono::high_resolution_clock::now();

    while(tt--){
        //cout << "Case #" << t - tt << ": ";
        go();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    //cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
    return 0;
}
/* ---------------- end of code ---------------- */