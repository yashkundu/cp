/**
*   author: lazyhash(yashkundu)
*   created: 30 Apr, 2023 | 15:46:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n;
    cin >> n;
    if(n==1) {
        cout << "1\n";
        return;
    }
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    if(n&1) {
        cout << "-1\n";
        return;
    }
    for(int i=0;i<n;i+=2) {
        int t = v[i+1];
        v[i+1] = v[i];
        v[i] = t;
    }
    for(int &x: v) cout << x << " ";
    cout << "\n";
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