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
int n;
int a[N];
void go() {
	cin >> n;
	forn(i,n)cin >> a[i];
	int ans=0;
	forn(i,n) {
		if(a[i]>10) ans += (a[i]-10);
	}
	cout<<ans<<ln;
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