/**
*   author: lazyhash(yashkundu)
*   created: 12 Mar, 2023 | 21:25:28
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
    ll a, b, c;
    cin >> a >> b >> c;
    // -2, 0, +2
    if((a+b+c)%3) {
        cout << "-1\n";
        return;
    }
    ll x = (a+b+c)/3;
    if((x-a)%2 || (x-b)%2 || (x-c)%2) {
        cout << "-1\n";
        return;
    }

    ll d = abs(x-a) + abs(x-b) + abs(x-c);
    cout << d/4 << "\n";



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