/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jun, 2024 | 14:37:04
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm> 

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
vector<int> v;

int n;

void solve() {
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int sum = v.back();
    v.pop_back();

    sort(v.rbegin(), v.rend());

    sum += v[0];
    cout << sum << "\n";

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