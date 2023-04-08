/**
*   author: lazyhash(yashkundu)
*   created: 02 Apr, 2023 | 20:06:05
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
    int n;
    cin >> n;
    vector<int> a(n);
    int tot_xor = 0;
    for(int &x: a) {
        cin >> x;
        tot_xor ^= x;
    }

    if(n%2==0) {
        if(tot_xor) {
            cout << "-1\n";
        } else {
            cout << "0\n";
        }
    } else {
        cout << tot_xor << "\n";
    }

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