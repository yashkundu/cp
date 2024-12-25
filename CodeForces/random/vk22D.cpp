/**
*    author:  lazyhash(yashkundu)
*    created: 19 Jul, 2024 | 18:50:49
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
vector<int> a;


bool ispsq(ll x) {
    ll y = llround(sqrtl(x));
    return y*y==x;
}


int findmx(ll x) {
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(ispsq(a[i]+x)) cnt++;
    } 
    return cnt;
}

int ans = 1;

 
void solve() {
    cin >> n;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];

    ans = 1;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            ll diff = a[j] - a[i];
            for(ll k=1;k*k<=diff;k++) {
                if(diff%k) continue;
                ll q = k + diff/k;
                if(q%2) continue;
                q /= 2;
                if(q*q>=a[j]) ans = max(ans, findmx(q*q - a[j]));
            }
        }
    }

    cout << ans << "\n";

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