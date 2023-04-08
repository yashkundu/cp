/**
*   author: lazyhash(yashkundu)
*   created: 01 Apr, 2023 | 20:29:22
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int l, r;
    cin >> l >> r;
    int max_l = -1, ans = -1;

    auto check = [&max_l, &ans](int x) {
        int d1 = 0, d2 = 10;
        int num = x;
        while(num>0) {
            d1 = max(d1, num%10);
            d2 = min(d2, num%10);
            num /= 10;
        }
        if(d1-d2>max_l) {
            max_l = d1-d2;
            ans = x;
        }
    };

    for(int i=l;i<=min(l+100, r);i++) check(i);

    cout << ans << "\n";

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/