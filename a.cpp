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


int n, m;
vector<vector<int>> v;
vector<set<int>> vcopy;
vector<int> ans;
vector<int> single;
vector<int> cnt;
void go() {
	cin >> n >> m;
	v.clear();
	vcopy.clear();
	ans.assign(m,-1);
	single.assign(n, 0);
	cnt.assign(n, 0);
	forn(i,m) {
		int tk;cin>>tk;
		vector<int> iN;iN.assign(tk,0);
		set<int> in;
		forn(j,tk) {
			cin >> iN[j];
			iN[j]--;
			cnt[iN[j]] ++;
			in.insert(iN[j]);
		}
		v.pb(iN);
		vcopy.pb(in);
		if(iN.size() == 1) {
			single[iN.back()] ++;
		}
	}
	bool more=false;
	int ind=-1;
	forn(i,n) {
		if(cnt[i] > (m+1)/2) {
			more=true;
			if(single[i] <= (m+1)/2) {
				ind = i;
			}
		}
	}
	if(!more) {
		cout << "YES\n";
		forn(i,m) {
			cout << v[i].back()+1 << " ";
		}
		cout << ln;
		return;
	}
	if(ind < 0) {
		cout << "NO\n";
		return;
	}
	int p = 0;
	forn(i,m) {
		if(v[i].size() == 1 and v[i].back() == ind) {
			ans[i] = ind;
			p ++;
		}
	}
	// cout << ind << " " << p << ln;
	assert(p <= (m+1)/2);
	int i = 0;
	while(p < (m+1)/2 and i < m) {
		if(ans[i] < 0 and vcopy[i].count(ind)) {
			assert(v[i].size() > 1);
			ans[i] = ind;
			p ++;
		}
		i ++;
	}
	// cout << p << ln;
	forn(i,m) {
		if(ans[i] < 0) {
			// assert(v[i].size() > 1);
			ans[i] = v[i][0];
			if(ans[i] == ind) ans[i] = v[i][1];
		}
	}
	cout << "YES\n";
	forn(i,m) cout << ans[i] +1<< " ";
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