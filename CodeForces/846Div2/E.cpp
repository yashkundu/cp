/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jan, 2023 | 20:17:49
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int SQRT = 30000;

void solve() {
    ll l, r;
    cin >> l >> r;
    ll cnt = 0;
    // case - 1
    // 1 2 3 4 ------------  l       r
    for(ll i=1;i<l;i++) {
        ll f = (l+i-1)/i;
        if(f<=SQRT) break;
        cnt += (r>=(f+1)*i);
    }


    auto get_ends = [&] (int f) -> pair<ll, ll> {
        return {(l+f-1)/f, (l+f-2)/(f-1)};
    };

    for(int i=2;i<=SQRT;i++) {
        auto [x1, x2] = get_ends(i);
        if(x1==x2) continue;
        ll y = r/(i+1)+1;
        cnt += max(min(x2, y) - x1, 0LL);
    }

    // case - 2
    // l .... 9 10 11 12 13 14  ...... r
    cnt += max(r/2-l+1, 0LL);

    cout << cnt << "\n";

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