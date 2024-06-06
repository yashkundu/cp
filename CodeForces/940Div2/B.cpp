/**
*   author: lazyhash(yashkundu)
*   created: 21 Apr, 2024 | 20:10:48
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
    if(n==1) {
        cout << k << "\n";
        return;
    }

    int x = k;
    int tot = 0, set = 0;
    while(x>0) {
        if(x&1) set++;
        tot++;
        x = (x>>1);
    }

    if(tot==set) {
        cout << k << " ";
        for(int i=0;i<n-1;i++) cout << 0 << " ";
        cout << "\n";
        return;
    }

    int first = (1<<(tot-1)) - 1;
    int second = k - first;

    cout << first << " " << second << " ";
    for(int i=0;i<n-2;i++) cout << 0 << " ";
    cout << "\n";
    return;





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