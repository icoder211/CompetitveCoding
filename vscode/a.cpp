/**
 * Author: icoder211
 */
 
#include<bits/stdc++.h>
using namespace std;

#define ln "\n"
#define pb push_back
#define Nos ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i = 0;i < n;i++)
#define forsn(i, s, n) for(int i  = s;i < n;i++)
#define all(v) v.begin(), v.end()
#define mp(i,j) {i,j}
 
typedef long double ld;
typedef long long ll;

ll exp(ll n, ll m, ll md) {
	ll res = 1;
	while(m > 0) {
		if(m&1) res = (res * 1ll * n) % md;
		n = (n*n) % md;
		m /= 2;
	}
	return res;
}

const int N = 201010;
ll n;
ll a[N];
vector<set<int>> ad;
ll md = 1e9+7;
map< set<ll>, ll> m, vis;
// map< set<ll>, set<ll> > neii;

ll calc(set<ll> s, set<ll> nei) {
	// neii[s] = nei;
	if(vis[s] > 0) 
		return m[s];
	if(s.size() == n) {
		m[s] = 0;
		vis[s] = 1;
		return 0;
	}
	vis[s] = 1;
	ll inv_ = exp((ll)nei.size(), md-2, md);
	for(auto y: nei) {
		set<ll> s_, nei_;
		s_ = s;
		s_.insert(y);
		nei_ = nei;
		for(auto u: ad[y]) {
			if(s.count(u)) continue;
			nei_.insert(u);
		}
		nei_.erase(y);

		ll p = calc(s_, nei_);
		for(auto u: s) {
			if(u > y) p ++;
		}
		p = (p * inv_) % md;
		m[s] += p;
		m[s] %= md;
	}

	return m[s];
}

void go() {
	cin >> n;
	ad.assign(n,{});
	forn(i,n-1) {
		int q,w;
		cin >> q>>w;q--;w--;
		ad[q].insert(w);
		ad[w].insert(q);
	}
	ll ans = 0;
	forn(i,n) {
		set<ll> s, nei; 
		s.insert(i);
		for(auto u: ad[i]) nei.insert(u);
		ans += calc(s, nei);
		// cout << ans << " " ;
		ans %= md;
	}
	// cout<<ln;
	// for(auto u: m) {
	// 	for(auto y: u.first) cout << y << " ";cout<<ln;
	// 	cout << u.second << ln;

	// 	for(auto u: neii[u.first]) cout<< u << " ";cout<<ln;
	// 	cout << ln;
	// }
	ans = (ans * exp(n, md-2, md)) % md;
	cout << ans << ln;
	
}

int main() {
    Nos;
	// seive();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	// freopen("in.txt","r",stdin);//freopen("output.txt","w",stdout);

	int t; t = 1;
    // cin >> t;
	int tt = t;

    while(t--) {
		// cout << "Case #"<<tt-t<<": ";
		go();
		// fflush(stdout);
	}
}