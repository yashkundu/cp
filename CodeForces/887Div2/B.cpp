/**
*   author: lazyhash(yashkundu)
*   created: 23 Jul, 2023 | 20:21:29
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, k;
    cin >> n >> k;
    auto calc = [](int a, int b) {
        assert(a<=b);
        int num = 2;
        while(b-a<=a) {
            num++;
            int del = b - a;
            b = a;
            a = del;
        }
        return num;
    };
    int ans = 0;
    for(int i=n;i>=0;i--) ans += calc(i, n) >= k;
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