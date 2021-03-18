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
 
ll exp(ll n, ll m, ll md) {
	ll res = 1;
	while(m > 0) {
		if(m&1) res = (res * 1ll * n) % md;
		n = (n*n) % md;
		m /= 2;
	}
	return res;
}
 
// ll n, m;
// // ll a[200005];
// // vector<int> cnt;
// void go() {
// 	cin >> n >> m;
// 	if(n&1) {
// 		cout << n/2 << " " << n/2 << " " << 1 << ln;
// 		return;
// 	}
// 	if(n%3 == 0) {
// 		cout << n/3 << " " << n/3 << " " << n/3 << ln;
// 		return;
// 	}
// 	if(n%4 > 0) cout << n/2-1 << " " << n/2-1 << " " << 2 << ln;
// 	else cout << n/4 << " " << n/4 << " " << n/2 << ln;
 
	
// }
 
// void go1() {
// 	cin >> n >> m;
// 	if(m >= n/2 + 1) {
// 		forn(i,m-1) cout << 1 << " ";
// 		cout << n - m + 1 << ln;
// 		return;
// 	}
// 	if( m <= 30 && n % (1ll << (ll)(m-1)) == 0) {
// 		cout << n / (1ll << (m-1)) << " ";
// 		while(m > 1) {
// 			cout << n / (1ll << (m-1)) << " ";
// 			m --;
// 		}
// 		cout << ln;
// 		return;
// 	}
	
// 	forn(i, m-1) {
// 		if((n-i) % (m-i) == 0) {
// 			forn(j, m-i) {
// 				cout << ((n-i) / (m-i)) << " ";
// 			}
// 			forn(j, i) cout << 1 << " ";
// 			cout << ln;
// 			return;
// 		}
// 	}
// 	assert(2 > 3);
// }
 
 
int n, k;
int a[200005];
vector<int> vis;
set<int> s;
vector<set<int>> v;
vector<int> pr;
vector<int> comb;
set<int> same;
void go2() {
	cin >> n >> k;
	int ans = 1;
	s.clear();
	comb.clear();
	// comb.pb(0);
	v.clear();
	forn(i, n) cin >> a[i];
	int T = 0;
	forn(i, n) {
		int p = a[i];
		int d = 0;
		int ss = 1;
		while(p > 1 and d < pr.size()) {
			int cnt = 0;
			while(p%pr[d]==0) {
				p/=pr[d];
				cnt++;
			}
			if(cnt%2 == 1) ss *= pr[d];
			d ++;
		}
		if(p > 1) ss *= p;

		if(s.count(ss)) {
			v.pb(s);
			s.clear();
			comb.pb(0);
			ans ++;
		}
		// else {
		// 	if(!v.empty()) {
		// 		if(v.back().count(ss)) comb.back()++;
		// 	}
		// }
		if(v.empty()) {
			same.insert(ss);
		}else {
			if(same.count(ss)) {
				comb.back()++;
				same.erase(ss);
			}else {
				same.insert(ss);
			}
		}
		s.insert(ss);
		a[i] = ss;
		if(i == n-1) {
			v.pb(s);
		}
	}
	forn(i, comb.size()-1) {
		comb[i+1] += comb[i];
	}
	// for(auto u: comb) cout << u << " ";
	sort(all(comb));
	reverse(all(comb));

	int s = 0;
	ans = v.size();
	while(!comb.empty() and s + comb.back() <= k) {
		s += comb.back();
		comb.pop_back();
		ans --;
	}
	cout << ans << ln;
	
 
}
 
int main() {
    IO;
	vis.assign(1e7+1, 0);
	int i =0 ;
	for(int i = 2;i * i <= 1e7; i++ ) {
		if(vis[i]) continue;
		pr.pb(i);
		for(int j = i*i;j <= 1e7;j += i) {
			vis[j] = 1;
		}
	}
	
	int t;cin >> t;
	while(t--) 
	{
		go2();
	}
 
	// cout << ans << ln;
	
	
}