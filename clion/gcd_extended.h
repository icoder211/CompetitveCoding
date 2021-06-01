/* ---------------- gcd_extended ---------------- */
/*
 * CAREFUL: Overflow at x *= c/g out of 10**18
 * Lookout for A = 0 or B = 0
 */
void shift(ll &x, ll& y, ll cnt, ll a, ll b) {
    x += cnt * b;
    y -= cnt * a;
}
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool give_range(ll a, ll b, ll c, ll mina, ll maxa, ll minb, ll maxb, ll &lx, ll &rx) {
    ll x, y;
    ll g = gcd(a, b, x, y);
    if(c % g != 0) return false;
//    out2(x, y);
    x *= c/g;
    y *= c/g;
//    out2(x, y);
    a /= g;
    b /= g;
    if(a == 0 || b == 0) {
        if(x >= mina && x <= maxa && y >= minb && y <= maxb) {
            lx = x;
            rx = x;
            return true;
        }
        return false;
    }
    ll sign_a = (a > 0 ? 1 : -1);
    ll sign_b = (b > 0 ? 1 : -1);
    ll lx1, lx2, rx1, rx2;
    {
        ll cnt = (mina - x)/b;
        shift(x, y, cnt, a, b);
        if(x < 0) shift(x, y, sign_a, a, b);
        if(x > maxa) {
            return false;
        }
//        out2(x, y);

        lx1 = x;
    }
    {
        ll cnt = (maxa - x)/b;
        shift(x, y, cnt, a, b);
//        out2(x, y);
        rx1 = x;
    }
    {
        ll cnt = -(minb - y)/a;
        shift(x,y, cnt, a, b);
        if(y < 0) shift(x,y,-sign_b, a, b);
        if(y > maxb) {
            return false;
        }
//        out2(x, y);

        lx2 = x;
    }
    {
        ll cnt = -(maxb - y)/a;
        shift(x, y, cnt, a, b);
//        out2(x, y);

        rx2 = x;
    }
    if(lx2 > rx2) swap(lx2, rx2);
//    out4(lx1, lx2, rx1, rx2);

    ll lxx = max(lx1, lx2);
    ll rxx = min(rx1, rx2);
    if(lxx > rxx) {
        return false;
    }
    lx = lxx;
    rx = rxx;
    return true;
}
