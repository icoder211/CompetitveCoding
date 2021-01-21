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
 
int n;
int a[2002];
set<int> s;
vector<pair<int, int>> ans;
bool f(int i, int p) {
	if(i < 0) return true;
	if(s.count(i)) return f(i-1, p);
	int st = lower_bound(a, a+i, p - a[i]) - a;
	if(st >= 0 and st < i and a[st] == p - a[i]) {
		// good
		int ed = upper_bound(a, a+i, p - a[i]) - a;
		int j = st;
		while(j < ed and s.count(j)) {
			j++;
		}
		if(j == ed or j == i) return false;
		s.insert(j);
		ans.pb({j, i});
		return f(i-1, a[i]);
	}else {
		return false;
	}
 
}
void go() {
	cin >> n;
	int cnt[1000006] = {0};
 
	bool ok = true;
	forn(i, 2*n) {
		cin >> a[i];
		cnt[a[i]]++;
		if(cnt[a[i]] > 100) ok = false; 
	}
	sort(a, a+2*n);
	if(!ok) {
		cout << "NO\n";
		return;
	}
	
	forn(i,2*n - 1) {
		// cout << i << ln;
		ans.clear();
		s.clear();
		if(f(2*n-1, a[2*n-1] + a[i])) {
			cout << "YES\n";
			cout << a[ans[0].first] + a[ans[0].second] << ln;
			for(auto u: ans) {
				cout << a[u.first] << " " << a[u.second] << ln;
			}
			return;
		}
		// else if(!ans.empty()) {
		// 	cout << a[ans[0].first] + a[ans[0].second] << ln;
		// 	for(auto u: ans) {
		// 		cout << a[u.first] << " " << a[u.second] << ln;
		// 	}
		// }
	}
	cout << "NO\n";
}
 
int main() {
    IO;
    
	int t;cin >> t;
	while(t--) 
	go();
	
	
}