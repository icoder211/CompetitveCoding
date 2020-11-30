#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
#define pb push_back
typedef long double ld;
typedef long long ll;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main() {
  IO;
  cout << "works!\n";
}













// const ll N = 2e5+11;
// ll n, h;
// ll t[2*N] = {0};
// ll d[N];
//
// void apply(int p, ll value) {
//   // t[p] += value;
//   if (p < n) d[p] = max(d[p], value);
//   else {
//     t[p] = max(t[p], value);
//   }
// }
//
// void build(int p) {
//   while (p > 1) p >>= 1, t[p] = (t[p<<1] + t[p<<1|1]) + d[p];
// }
//
// void push(int p) {
//   for (int s = h; s > 0; --s) {
//     int i = p >> s;
//     if (d[i] != 0) {
//       apply(i<<1, d[i]);
//       apply(i<<1|1, d[i]);
//       d[i] = 0;
//     }
//   }
// }
//
// void inc(int l, int r, ll value) {
//   l += n, r += n;
//   int l0 = l, r0 = r;
//   for (; l < r; l >>= 1, r >>= 1) {
//     if (l&1) apply(l++, value);
//     if (r&1) apply(--r, value);
//   }
//   build(l0);
//   build(r0 - 1);
// }
//
// ll query(int l, int r) {
//   l += n, r += n;
//   push(l);
//   push(r - 1);
//   int res = 0;
//   for (; l < r; l >>= 1, r >>= 1) {
//     if (l&1) res += t[l++];
//     if (r&1) res += t[--r];
//   }
//   return res;
// }
//
// int bs(int x, ll y) {
//   int l = x, r = n;
//   while(l < r) {
//     int m = (l + r) / 2;
//     if(query(m) > y) {
//       l = m+1;
//     }else {
//       r = m;
//     }
//   }
//   // cout << r << " ";
//
//   return r;
// }
//
// int main() {
//   cin >> n;int q;cin >> q;
//   h = sizeof(int) * 8 - __builtin_clz(n);
//
//   for(int i = 0;i < n;i++) {
//     cin >> t[n+i];
//   }
//   for(int i = 0;i < q;i++) {
//     int tk, x, y;
//     cin >> tk;cin >> x>>y;
//     if(tk == 1) {
//       update(0, x, y);
//     }else {
//       x--;
//       int ans = 0;
//       // cout << "HAHA\n";
//       while(x < n) {
//         // search for hotel
//         int r = bs(x, y);
//         if(r >= n) {
//           break;
//         }
//         ans++;
//         y -= query(r);
//         x = r+1;
//       }
//       cout << ans << ln;
//     }
//   }
// }
