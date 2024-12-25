/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jun, 2024 | 18:57:53
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int n, m;
ll ans = 0;
int sum = 0;
 
void solve() {
    cin >> n >> m;
    ans = 0;


    sum = 0;
    for(int i=1;i*i<=n;i++) {
        for(int j=1;j*j<=m;j++) {
            if(gcd(i, j)!=1) continue;
            sum = (i+j);
            ans += min(1LL*n/(1LL*i*sum), 1LL*m/(1LL*j*sum));
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