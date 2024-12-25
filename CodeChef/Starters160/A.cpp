/**
*    author:  lazyhash(yashkundu)
*    created: 13 Nov, 2024 | 20:34:44
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> b;
 
void solve() {
    cin >> n;
    b.resize(n);

    for(int i=0;i<n;i++) cin >> b[i];

    if(b[0]==0 && b[n-1]==1) {
        cout << 2 + 2*(n-2) << "\n";
        return;
    }

    cout << 1 + 2*(n-1) << "\n";



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