/**
*    author:  lazyhash(yashkundu)
*    created: 30 Oct, 2024 | 20:22:09
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
int a;
int cnt[30];
 
void solve() {
    cin >> n;
    fill(cnt, cnt+30, 0);


    for(int i=0;i<n;i++) {
        cin >> a;
        for(int j=0;j<30;j++,a>>=1) {
            if(a&1) cnt[j]++;
        }
    }


    ll ans = 0;
    ll f = 1;


    for(int i=0;i<30;i++,f<<=1) {
        if(cnt[i]==n) ans += f;
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