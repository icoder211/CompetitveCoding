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
const int N = 201;
map<char, int> c;
vector<char> dirs = {'E', 'S', 'W', 'N'};
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
char a[N][N];

ll vis[200][200] = {0};
bool chk(int i, int j) {
    if(i < 0 or j < 0 or i >= n or j >= m) return 0;
    return 1;
}
vector<int> eu0, eu1;
string ans;
void dfs(int i, int j, int dir) {
    if(a[i][j] == '#') return;
    if(vis[i][j]) return;
    vis[i][j] = 1;
    eu0.pb(i);
    eu1.pb(j);
    int ch = 0;
    fo(k0, 3) {
        int k = dir + 1 - k0 + 4;
        k %= 4;
        int x = i + dr[k];
        int y = j + dc[k];
        if(!chk(x, y) or vis[x][y] or a[x][y] == '#') {
            ans.pb(dirs[(k+3)%4]);
            continue;
        }
        ch++;
        ans.pb(dirs[k]);
        dfs(x, y, k);
        ans.pb(dirs[(k+2)%4]);
    }
}
void go1() {
    c['N'] = 3;c['S'] = 1; c['E'] = 0; c['W'] = 2;
    ans = "";
    cin >> n >> m;

    fo(i,n) {
        string s;cin >> s;
        fo(j,m) {
            a[i][j] = s[j];
            vis[i][j] = 0;
        }
    }
    eu0.clear(); eu1.clear();
    dfs(0, 0, 1);
    ans += 'W';
    fo(i,n) {
        fo(j,m) {
            if(vis[i][j] or a[i][j] == '#') {}
            else {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
    // int x = 0, y =0;
    // fo(i,ans.size()) {
    //     x += dr[c[ans[i]]];
    //     y += dc[c[ans[i]]];
    //     out2(x,y);
    // }
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