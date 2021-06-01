/*
 * Add this:
 * forn(i,<that n>) lk[i] = i;forn(i,n) sz[i] = 1;
 */

int lk[MAXn];
int sz[MAXn];
int find(int s) {
    while(s != lk[s]) s = lk[s];
    return s;
}
void unite(int s, int r) {
    s = find(s);
    r = find(r);
    if(s == r) return;
    if(sz[s] < sz[r]) swap(s, r);
    lk[r] = s;
    sz[s] += sz[r];
}
