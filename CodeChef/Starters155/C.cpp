/**
*    author:  lazyhash(yashkundu)
*    created: 09 Oct, 2024 | 20:30:29
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
vector<int> a;
 
void solve() {
    cin >> n;
    b.resize(n);
    a.resize(n);


    for(int i=0;i<n;i++) cin >> b[i];


    a[0] = (int)2e6;
    for(int i=1;i<n;i++) a[i] = b[i] - b[i-1];

    for(int i=0;i<n;i++) cout << a[i] << " ";
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