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
vector<vector<pair<ll, ll>>> ad;
vector<ll> vis;
vector<ll> path, mx, mn;
void go() {
	cin >> n >> m;
	ad.assign(n, {});
	vis.assign(n, 0);
	path.assign(n, 1e16+7);
	mn.assign(n, 1e9+1);
	mx.assign(n, -1);

	path[0] = 0;
	mx[0] = 0;
	mn[0] = 1e9+1;

	forn(i,m) {
		ll u, v, t;cin >> u >> v >> t;
		// cout << u << v << t << endl;
		u--;v--;
		ad[u].pb({v, t});
		ad[v].pb({u, t});
	}
	priority_queue<pair<ll, ll>> q;
	q.push({0, 0});

	while(!q.empty()) {
		auto uu = q.top();
		q.pop();
		ll u = uu.second;
		// cout << "u " << u << endl;
		if(vis[u]) continue;

		for(pair<ll, ll> yy: ad[u]) {
			if(vis[yy.first]) continue;
			int y = yy.first;
			if(path[y] - mx[y] + mn[y] >  path[u] - max(mx[u], yy.second) + min(mn[u], yy.second) + yy.second) {
				path[y] = path[u] + yy.second;
				mx[y] = max(mx[u], yy.second);
				mn[y] = min(mn[u], yy.second);
				q.push({- (path[y] - mx[y] + mn[y]), y});
			}
		}
		vis[u] = 1;
	}
	forsn(i, 1, n) {
		cout << path[i] - mx[i] + mn[i] << " ";
	}
	cout << ln;
}

 
int main() {
    IO;
    
	// int t;cin >> t;
	// while(t--)
	go();
	
}