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


ll n, m;
pair<ll, ll>  a[100005];
vector<set<ll>> ad;
vector<pair<ll, ll>> s;

// int lk[100005];
// int sz[100005];
// int find(int s) {
// 	while(s != lk[s]) s = lk[s];
// 	return s;
// }
// void unite(int s, int t) {
// 	s = find(s);
// 	t = find(t);
// 	if(s == t) return;
// 	if(sz[s] < sz[t]) swap(s, t);
// 	lk[t] = s;
// 	sz[s] += sz[t];
// }
vector<ll> vis;
vector<ll> ans;
vector<ll> cur = {};
ll szz = 0;
void dfs(ll s) {
	// unite(rep, s);
	cur.pb(s);
	szz++;
	vis[s] = 1;
	for(auto u: ad[s]) {
		if(vis[u] > 0) continue;
		dfs(u);
	}
}

void go() {
	cin >> n >> m;
	priority_queue<pair<ll, ll>> qq;
	forn(i,n) {
		cin >> a[i].first;
		a[i].second = i;
		qq.push({a[i].first, a[i].second});
	}
	szz = 0;
	ans.assign(n, -1);
	// forn(i, n) {
	// 	lk[i] = i;
	// 	sz[i] = 1;
	// }
	vis.assign(n, 0);
	ad.assign(n, {});
	s.assign(n, {});
	
	// sort(a,a+n);reverse(a, a+n);
	forn(i, m) {
		ll t, ss;cin >> t >> ss;
		t--;
		ss--;
		// unite(t, s);
		if(t == ss) continue;
		ad[t].insert(ss);
		ad[ss].insert(t);
	}
	if(n == 1) {
		cout << 1 << ln;
		return;
	}
	priority_queue<pair<ll, ll>> q;
	forn(i, n) {
		cur.clear();szz = 0;
		if(vis[i] > 0) continue;
		dfs(i);
		for(auto u: cur) {
			q.push({szz, u});
		}
	}
	cur.clear();szz = 0;
	ll i = 0;
	set<ll> chk;

	assert(q.size() == n);
	assert(qq.size() == n);
	while(!q.empty()) {
		auto u = q.top();
		q.pop();
		auto uu = qq.top();
		qq.pop();
		// assert(uu.second >= 0 and uu.second < n and u.second >= 0 and u.second < n);
		// assert(ans[uu.second] == -1);
		// assert(!chk.count(u.second));
		ans[uu.second] = u.second;
		// chk.insert(u.second);
	}
	forn(i, n) {
		cout << ans[i] + 1ll << " ";
	}
	cout << ln;

}




int main() {
    IO;
    fflush(stdout);
	// int t;cin >> t;
	// while(t--) 
	go();
	
	
}