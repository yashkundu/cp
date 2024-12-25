/**
*    author:  lazyhash(yashkundu)
*    created: 30 Jun, 2024 | 14:01:50
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

const int MAXN = 2e5+10;

int n;
ll k;

ll a[MAXN];
 
void solve() {
    cin >> n >> k;
    bool pos = 0, neg=0, zer=0;
    ll tot = 0;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i] -= k;
        if(a[i]>0) pos = 1;
        else if(a[i]<0) neg = 1;
        else zer = 1;
        tot += a[i];
    }

    if(pos+neg+zer>1) {
        cout << "-1\n";
        return;
    }

    if(zer) {
        cout << "0\n";
        return;
    }

    ll g = 0;
    for(int i=0;i<n;i++) g = gcd(g, abs(a[i]));

    cout << abs(tot)/g - n << "\n";


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