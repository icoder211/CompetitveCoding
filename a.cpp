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
void seive() {
	// vis.assign(1e7+1, 0);
	// int i =0 ;
	// for(int i = 2;i * i <= 1e7; i++ ) {
	// 	if(vis[i]) continue;
	// 	pr.pb(i);
	// 	// cout << i << " ";
	// 	for(int j = i*i;j <= 1e7;j += i) {
	// 		vis[j] = 1;
	// 	}
	// }
}


int n;
ll a[100000];
void go() {
	cin >> n;
	forn(i,n) cin>>a[i];
	vector<int> m(n, 0);
	forn(i,n) m[i] = i+1;
	m[n-1]=0;
	vector<int> ans;
	set<int> trav;
	forn(i,n)trav.insert(i);
	while(trav.size()>0) {
		int i = 0;
		set<int>neutrav,remtrav;
		for(auto i: trav) {
			if(remtrav.count(i)) continue;
			if(__gcd(a[i],a[m[i]])==1){
				remtrav.insert(m[i]);
				ans.pb(m[i]+1);
				m[i]= m[m[i]];
			}
			if(__gcd(a[i],a[m[i]])==1){
				neutrav.insert(i);
			}
		}
		for(auto u: remtrav) neutrav.erase(u);
		trav = neutrav;
	}
	cout << ans.size()<<" ";
	for(auto u: ans) {
		cout <<u<< " ";
	}
	cout << ln;
}


int main() {
    IO;
	// vis.assign(1e7+1, 0);
	// int i =0 ;
	// for(int i = 2;i * i <= 1e7; i++ ) {
	// 	if(vis[i]) continue;
	// 	pr.pb(i);
	// 	// cout << i << " ";
	// 	for(int j = i*i;j <= 1e7;j += i) {
	// 		vis[j] = 1;
	// 	}
	// }
	
	int t;cin >> t;
	int tt = t;
	while(t--) 
	{
		// cout << "Case #" << tt-t << ": ";
		go();
	}
 
	// cout << ans << ln;
	
	
}