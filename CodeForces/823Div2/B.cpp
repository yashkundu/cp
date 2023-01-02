/**
*    author:  lazyhash(yashkundu)
*    created: 02 Jan,2023 | 13:14:33
**/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

pair<ld, ld> intersect(const pair<ld, ld> &seg1,const pair<ld, ld> &seg2) {
    return pair<ld, ld>(max(seg1.first, seg2.first), min(seg1.second, seg2.second));
}

ld isValid(ld time, vector<ll> &x, vector<ll> &t) {
    pair<ld, ld> seg = {0, 1e9};
    for(int i=0;i<x.size();i++) {
        if(t[i]>time) return -1;
        seg = intersect(seg, make_pair(x[i]-time+t[i], x[i]+time-t[i]));
        if(seg.second<seg.first) return -1;
    }
    return seg.first;
}


void solve() {
    int n;
    cin >> n;

    vector<ll> x(n, 0);
    for(int i=0;i<n;i++) cin >> x[i];

    vector<ll> t(n, 0);
    for(int i=0;i<n;i++) cin >> t[i];

    // 
    ld l = 0, r = 1e9;

    for(int i=0;i<100;i++) {
        ld mid = (l+r)/2;
        if(isValid(mid, x, t)!=-1) r = mid;
        else l = mid;
    }

    cout << setprecision(10) << isValid(r, x, t) << "\n";

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