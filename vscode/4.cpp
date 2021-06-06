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

const int N = 101;
int n;
int a[N];
int dp[N][2][101010] = {0};
void go() {
    cin >> n;
    forn(i,n) cin >> a[i];
    
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