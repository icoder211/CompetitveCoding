/**
 * Author: icoder211
 */

#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
#define pb push_back
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(ll i = 0;i < n;i++)
#define forsn(i, s, n) for(ll i  = s;i < n;i++)
#define all(v) v.begin(), v.end()
 
typedef long double ld;
typedef long long ll;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};

ll exp(ll n, ll m, ll md) {
	ll res = 1;
	n %= md;
	while(m > 0) {
		if(m&1) res = (res * 1ll * n) % md;
		n = (n*1ll*n) % md;
		if(n<0) {
			// cout << n << " " << m << " " << md << endl;
			assert(n>=0);
		}
		m /= 2;
	}
	return res;
}
ll gcd(ll c, ll d, ll &x, ll &y) {
	if(d == 0) {
		x = 1;
		y = 0;
		return c;
	}
	ll g = gcd(d, c%d, x, y);
	ll x0 = y;
	ll y0 = x - y*(c/d);
	x=x0;
	y=y0;
	return g;
}

const ll N = 501;
vector<ll> pr;
vector<ll> lp;
// vector<int> g[N];
void seive() {
	int N = 2e5+1;
	vector<ll> vis;
	lp.assign(N, -1);
	pr.clear();
	vis.assign(N, 0);
	ll i = 0;
	for(ll i = 2;i <= N; i++ ) {
		if(vis[i]) continue;
		pr.pb(i);
		for(ll j = i;j <= N;j += i) {
			vis[j] = 1;
			if(lp[j] == -1) lp[j] = i;
			// g[j].pb(i);
		}
	}
}


ll mod = 1e9+7;
// ll mod = 998244353;
// ll f(int d) {
// 	int ans = 0;
// 	forn(i,32) {
// 		if(d & (1 << i)) {
// 			ans ++;
// 		}
// 	}
// 	return 32 - ans;
// }
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
    forsn(i,1,200009){
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


int n, a, b;
int c[N];
bool chk(int p) {
	if(p < n) return false;
	vector<int> q;
	forn(i, p+1) {
		q.pb(0);
	}
	q[p] ++;
	while(p >= 0) {
		if(q[p] < c[p]) return false;
		int d = q[p] - c[p];
		q[p] = c[p];
		if(p-a >= 0) q[p-a] += d;
		if(p-b >= 0) q[p-b] += d;
		p--;
	}
	return true;
}
void go() {
	cin >> n >> a >> b;
	forn(i,n) {
		cin >> c[i];
	}
	forsn(i,n,501) c[i] = 0;
	forsn(i, n, 403) {
		if(chk(i)) {
			cout << i+1 << ln;
			return;
		}
	}
	cout << "IMPOSSIBLE\n";
}


int main() {
    IO;
	// fac();
	// seive();
	cout.flush();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t; t = 1;
    cin >> t;
	int tt = t;
    while(t--) {
		cout << "Case #"<<tt-t<<": ";
		go();
	}
}