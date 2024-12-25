/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jul, 2024 | 13:52:01
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXA = int(1e6)+2;
const int MAXN = int(2e5)+10;
const int SQR = 1001;

int n;
int a[MAXN];

int cnt[MAXA];

ll ans;

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ans = 0;
    for(int b=2;b<SQR;b++) {
        for(int i=0;i<n;i++) {
            if(a[i]*b<MAXA && 1LL*a[i]*b*b<MAXA) ans += cnt[b*a[i]]*cnt[b*b*a[i]];
        }
    }

    for(int i=0;i<n;i++) {
        ans += 1LL*cnt[a[i]]*(cnt[a[i]]-1)*(cnt[a[i]]-2);
        cnt[a[i]] = 0;
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