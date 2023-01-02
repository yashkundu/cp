/**
*    author:  lazyhash(yashkundu)
*    created: 02 Jan,2023 | 14:07:14
**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

// x1        x2
// l         r
// {time, x}
pair<ld, ld> calc(ll l, ll r, ll x1, ll x2) {
    if(l<r) {
        ll d = min(x2-x1, r-l);
        l += d;
        x1 += d;
    } else if(r<l) {
        ll d = min(x2-x1, l-r);
        r += d;
        x2 -= d;
    }
    if(l==r) {
        return pair<ld, ld>((ld)(x2-x1)/2 + l, (ld)(x2-x1)/2+x1);
    } else {
        if(l<r) return pair<ld, ld>(r, x2);
        else return pair<ld, ld>(l, x1);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n, 0), t(n, 0), mSuf(n+2, 0);

    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++) cin >> t[i];

    // 1 5 9 10 58 89
    vector<pair<ll, ll>> v;
    v.emplace_back(0,0);
    for(int i=0;i<n;i++) v.emplace_back(x[i], t[i]);
    v[0].first = v[1].first;

    sort(v.begin()+1, v.end());
    v.emplace_back(v[n].first, 0);

    for(int i=n;i>0;i--) {
        mSuf[i] = max(mSuf[i+1]+v[i+1].first-v[i].first, v[i].second);
    }

    ld ans = v[1].first;
    ll pre = 0;
    ld minTime = 1e9;
    for(int i=1;i<n;i++) {
        // v[i]        v[i+1]
        // 15          98
        pre = max(pre+v[i].first-v[i-1].first, v[i].second);
        ll l = pre;
        ll r = mSuf[i+1];
        pair<ld, ld> p = calc(l, r, v[i].first, v[i+1].first);
        if(p.first<minTime) {
            minTime = p.first;
            ans = p.second;
        }
    }

    cout << setprecision(10) << ans << "\n";



}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/