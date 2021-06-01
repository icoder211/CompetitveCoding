/**
 *    author:  tourist
 *    created: 06.06.2020 17:01:53       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    string a, b;
    cin >> a >> b;
    int na = (int) a.size();
    int nb = (int) b.size();
    const int inf = 787788;
    vector<vector<int>> f(na + 1, vector<int>(nb + 1));
    for (int i = 0; i <= na; i++) {
      for (int j = 0; j <= nb; j++) {
        if (i + j == 0) {
          continue;
        }
        f[i][j] = inf;
        if (i > 0 && j > 0 && a[i - 1] == b[j - 1]) {
          f[i][j] = min(f[i][j], f[i - 1][j - 1]);
        }
        if (i > 0 && j > 0 && a[i - 1] != b[j - 1]) {
          f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
        if (i > 0) {
          f[i][j] = min(f[i][j], f[i - 1][j] + 1);
        }
        if (j > 0) {
          f[i][j] = min(f[i][j], f[i][j - 1] + 1);
        }
      }
    }
    vector<string> ops(1, a);
    {
      int i = na, j = nb;
      while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && a[i - 1] == b[j - 1] && f[i][j] == f[i - 1][j - 1]) {
          i -= 1;
          j -= 1;
          continue;
        }
        if (i > 0 && j > 0 && a[i - 1] != b[j - 1] && f[i][j] == f[i - 1][j - 1] + 1) {
          a[i - 1] = b[j - 1];
          ops.push_back(a);
          i -= 1;
          j -= 1;
          continue;
        }
        if (i > 0 && f[i][j] == f[i - 1][j] + 1) {
          a.erase(a.begin() + (i - 1));
          ops.push_back(a);
          i -= 1;
          continue;
        }
        if (j > 0 && f[i][j] == f[i][j - 1] + 1) {
          a.insert(a.begin() + i, b[j - 1]);
          ops.push_back(a);
          j -= 1;
          continue;
        }
        assert(false);
      }
    }
    int dist = f[na][nb];
    assert((int) ops.size() == dist + 1);
    cout << ops[dist / 2] << '\n';
  }
  return 0;
}
