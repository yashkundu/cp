/**
*   author: lazyhash(yashkundu)
*   created: 11 Sep, 2023 | 22:47:17
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
    int n, k;
    cin >> n >> k;
    vector<bool> isPresent(n+1, 0);
    vector<int> p(n+1);
    for(int i=0;i<n;i++) {
        cin >> p[i];
        isPresent[p[i]] = 1;
    }
    int leftEl = -1;
    for(int i=0;i<=n;i++) if(!isPresent[i]) leftEl = i;
    p[n] = leftEl;
    k %= (n+1);
    int startInd = (n+1-k)%(n+1);
    for(int i=0;i<n;i++) cout << p[(startInd+i)%(n+1)] << " ";
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