/**
*    author:  lazyhash(yashkundu)
*    created: 03 Jul, 2024 | 14:18:37
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

int n, m;
vector<int> a, b;
vector<int> c;
 
void solve() {
    cin >> n >> m;
    a.resize(n);
    b.resize(m);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    sort(b.rbegin(), b.rend());
    c.resize(n+m);

    int i = 0, j = 0;
    for(int k=0;k<n+m;k++) {
        if(j<m && (i==n || a[i]<b[j])) c[k] = b[j++];
        else c[k] = a[i++];
    }

    for(int i=0;i<n+m;i++) cout << c[i] << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/