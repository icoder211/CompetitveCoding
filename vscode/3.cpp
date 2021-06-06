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

const int N = 101010;
int n, m;
vector<vector<int>> ad;
vector<int> vis;
int dfs(int s) {
    if(vis[s]) return 0;
    // cerr << s << " ";
    int ans = 0;
    ans ++;
    vis[s] = 1;
    for(auto u: ad[s]) {
        ans += dfs(u);
    }
    return ans;
}
void go() {
    cin >> n >> m;
	ad.assign(n,{});
    forn(i,m) {
        int a,b;cin >> a>>b;
        a--;b--;
        ad[a].pb(b);
    }
    int ans = 0;
    forn(i,n) {
        vis.assign(n,0);
        ans += dfs(i);
        // cerr << ln;
    }
    cout << ans << ln;
}

int main() {
    Nos;
	int t; t = 1;
    // cin >> t;
	int tt = t;

    while(t--) {
		go();
	}
}