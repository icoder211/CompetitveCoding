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

const ll N = 101;
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


int c,d;
int a[N];
vector<int> ad[N];
int vis[N];
ll dis[N]={0};
map< pair<int,int> , int> m;
int ans[1010];
vector<pair<int,int>> pos, neg;
set<int> done;
void go() {
	done.clear();
	cin >> c >> d;
	// cout<<c<<" " << d << endl;
	ad[0].clear();
	vis[0] = 0;
	dis[0] = 0;
	pos.clear(); neg.clear();
	forsn(i,1,c) {
		dis[i] = -1;
		cin >> a[i];
		
		if(a[i] > 0) {
			pos.pb({a[i], i});
		}else {
			neg.pb({-(a[i]+1), i});
		}

		ad[i].clear();
		vis[i] = 0;
	}
	forn(i,d) {
		int l , r;
		cin >> l >> r;l --; r --;
		m[{min(l,r), max(l,r)}] = i;
		ad[l].pb(r);
		ad[r].pb(l);
	}
	sort(all(pos));
	reverse(all(pos));
	for(auto p: pos) dis[p.second] = p.first;
	sort(all(neg));
	int i = 0;
	int prev = 0;
	// for(auto u: neg) {
	// 	cout << u.first << " " << u.second << endl;
	// }
	int com = 0;
	while(i < neg.size()) {
		int p = neg[i].first - com; assert(p >= 0);
		while(p > 0) {
			if(pos.empty()) {
				cout << i << " " << p << endl;
				assert(2>3);
			}
			prev = pos.back().first;
			pos.pop_back();
			com ++;
			p--;
		}
		int j = i;
		while(j < neg.size() and neg[j].first == neg[i].first) {
			dis[neg[j].second] = prev + 1;
			j++;
		}
		prev++;
		com += (j-i);
		i = j;
		while(!pos.empty() and pos.back().first == prev) {
			pos.pop_back();
			com++;
		}
	}
	// forn(i,c) {
	// 	cout << dis[i] << " " ;
	// }
	// cout << endl;
	vis[0] = 1;
	priority_queue<pair<int, int>> q;
	for(auto u: ad[0]) q.push({-dis[u], u});
	while(!q.empty()) {
		auto u = q.top(); q.pop();
		int p = u.second;
		if(vis[p]) continue;
		vis[p] = 1;
		bool ok = false;
		for(auto ch: ad[p]) {
			if(vis[ch]) {
				if(dis[ch] >= dis[p]) continue;
				ok = true;
				ans[m[{min(ch,p),max(ch,p)}]] = dis[p] - dis[ch];
			} else {
				q.push({-dis[ch], ch});
			}
		}
		assert(ok);
	}
	forn(i,d) {
		if(ans[i] == -1) ans[i] = 1e6;
		cout << ans[i] << " ";
	}
	cout << ln;


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