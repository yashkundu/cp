/**
*    author:  lazyhash(yashkundu)
*    created: 16 Sep, 2024 | 20:51:19
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, q;
int a, b, x;
int ta, tb;
 
void solve() {
    cin >> n >> m >> q;
    cin >> ta >> tb >> x;
    a = min(ta, tb);
    b = max(ta, tb);

    if(x<a) {
        cout << (a-1) << "\n";
        return;
    }

    if(x>b) {
        cout << (n-b) << "\n";
        return;
    }

    if(b-a==1) {
        cout << "1\n";
        return;
    }

    cout << (b-a-2) << "\n";




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