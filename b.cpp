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
	while(m > 0) {
		if(m&1) res = (res * 1ll * n) % md;
		n = (n*n) % md;
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

const ll N = 505;
vector<ll> pr;
vector<int> g[N];
void seive() {
	vector<ll> vis;
	pr.clear();
	vis.assign(1e5+1, 0);
	ll i = 0;
	for(ll i = 2;i <= 1e5; i++ ) {
		if(vis[i]) continue;
		pr.pb(i);
		// cout << i << " ";
		for(ll j = i;j <= 1e5;j += i) {
			vis[j] = 1;
			g[j].pb(i);
		}
	}
}


ll mod = 1e9+7;
// ll mod = 998244353;
ll f(int d) {
	int ans = 0;
	forn(i,32) {
		if(d & (1 << i)) {
			ans ++;
		}
	}
	return 32 - ans;
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


ll n, q, m;
ll md = 1e9+7;
// set<ll> s;
// pair<ll,ll> a[N];
// ll nxt[N], par[N]={0}, nxt2[N];// next index and no. of partitions by then

// bool chk(ll r) {
// 	for(auto u: s) if(r%u == 0) return false;
// 	return true;
// }

// void go() {
// 	// cout << __gcd(66977, 91733)<< ln;
// 	cin >> n >> q;
// 	m = floor(sqrt(n));
// 	forn(i,n) cin >> a[i];
// 	forn(i,n) nxt[i] = -1;
// 	ll i = 0;
// 	while(i < n) {
// 		int j = i+1;
// 		// cout << i << ln;
// 		while(j < n and i < j) {
// 			// cout << i << ln;
// 			if(!chk(a[j])) {
// 				// cout << i << " " << j << " " << pro << " " << a[j] << ln;
// 				nxt[i] = j;
// 				for(auto u: g[a[i]]) s.erase(u);
// 				i ++;
// 				continue;
// 			}
// 			for(auto u: g[a[j]]) {
// 				s.insert(u);
// 			}
// 			j++;
// 		}
// 		if(j == n) {
// 			break;
// 		}
// 	}
// 	forn(i,n) {
// 		if(nxt[i] == -1) nxt[i] = n;
// 		cout << i << " " << nxt[i] << endl;
// 		assert(i < nxt[i] and nxt[i] <= n);
// 	}
// 	forsn(i,1,n) {
// 		assert(nxt[i] >= nxt[i-1]);
// 		if(nxt[i] > nxt[i-1]) {
// 			if(__gcd(a[nxt[i-1]], a[i-1]) == 1) {
// 				forn(i,n) {
// 					cout << i << " " << nxt[i] << endl;
// 				}
// 				assert(2>3);
// 			}
// 		}
// 	}
// 	i = 0;
// 	while(i < n) {
// 		int j = i;
// 		while(j < i+m and j < n) {
// 			j = nxt[j];
// 			par[i]++;
// 			nxt2[i] = j;
// 		}
// 		i++;
// 	}
// 	forn(i,n) {
// 		assert(i < nxt2[i]);
// 	}
// 	// forn(i,n) {
// 		// cout<< i << " " << nxt[i] <<" " << par[i]<<endl;
// 	// }
// 	// return;
// 	forn(it, q) {
// 		int l, r; 
// 		cin >> l >> r;
// 		l--;
// 		int p = l;
// 		int ans = 0;
// 		// while(nxt2[p] < r) {
// 		// 	// cout<<p<<endl;
// 		// 	ans += par[p];
// 		// 	p = nxt2[p];
// 		// }
// 		while(p < r) {
// 			// cout<<p<<endl;
// 			p = nxt[p];
// 			ans ++;
// 		}
// 		assert(ans > 0 and ans <= (r-l));
// 		cout << ans << ln;
// 	}
// }


// void go1() {
// 	cin >> n >> m;
// 	ll ans[n][m];
// 	// map<ll,ll> rev;
// 	map<ll,ll> st[n];
// 	forn(i,n) {
// 		forn(j,m) {
// 			cin >> a[i*m+j].first;
// 			a[i*m+j].second = i*m+j;
// 			ans[i][j] = -1;
// 			st[i][ a[i*m+j] ]++;
// 		}
// 	}
// 	sort(a,a+m*n);
// 	forn(i,m) {
// 		ll x = a[i].second/m; ll y = a[i].second%m;
// 		ans[x][y] = a[i].first;
// 		cout << x << " " << y << " " << a[i].first<< endl;
// 		assert(st[x][a[i].first] > 0);
// 		st[x][a[i].first]--;
// 		if(st[x][a[i].first]==0) st[x].erase(a[i].first);
// 	}
// 	forn(i,n) {
// 		forn(j,m) {
// 			if(ans[i][j] == -1) {
// 				ans[i][j] = st[i].begin()->first;
// 				st[i].erase(st[i].begin());
// 			}
// 		}
// 	}
// 	// forn(it,m) {
// 	// 	rev[a[it].second] = it;
// 	// }
// 	// forn(it,m) {
// 	// 	int x = a[it].second/m;
// 	// 	int y = a[it].second%m;
// 	// 	if(y == it) continue;
// 	// 	while(rev.find(x*m+y) != rev.end()) {
// 	// 		ll p = rev[x*m+y];
// 	// 		a[p].second = x*m + y;
// 	// 		if(rev.find(x*m+p) != rev.end()) {
// 	// 			rev[x*m+y] = rev[x*m + p];
// 	// 			a[rev[x*m+p]].second = x*m+y;
// 	// 		}
// 	// 		rev.erase(x*m+y);
// 	// 		swap(ans[x][y], ans[x][p]);
// 	// 		break;
// 	// 		y = p;
// 	// 	}
// 	// }
// 	forn(i,n) {
// 		forn(j,m) {
// 			cout<<ans[i][j] << " ";
// 		}
// 		cout<<ln;
// 	}
// }

ll k;
ll a[N];
ll dp[N][20];
void go() {
	
	cin >> n >> k;
	forn(i,n) {
		cin >> a[i];
	}
	stack<ll> st;
	

}

int main() {
    IO;
	// fac();
	// seive();
	// cout.flush();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t; t = 1;
    // cin >> t;
	int tt = t;
    while(t--) {
		// cout << "Case #"<<tt-t<<": ";
		go();
	}
}