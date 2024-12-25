/**
*    author:  lazyhash(yashkundu)
*    created: 13 Oct, 2024 | 16:10:10
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int MAXN = (int)5e6+10;
int cnt[MAXN] = {0};
ll dp[MAXN] = {0};



int n;
vector<int> a;
int f;

 
void solve() {
    cin >> n;
    a.resize(n);

    for(int i=0;i<n;i++) {
        cin >> a[i];
        for(int j=1;j*j<=a[i];j++) {
            if(a[i]%j) continue;
            cnt[j]++;
            if(j!=a[i]/j) cnt[a[i]/j]++;
        }
    }


    for(int i=MAXN-1;i>=1;i--) {
        dp[i] = max(dp[i], 1LL*i*cnt[i]);
        if(!dp[i]) continue;
        for(int j=1;j*j<=i;j++) {
            if(i%j) continue;
            dp[j] = max(dp[j], dp[i] + 1LL*j*(cnt[j]-cnt[i]));
            f = i/j;
            dp[f] = max(dp[f], dp[i] + 1LL*f*(cnt[f]-cnt[i]));
        }
    }

    cout << dp[1] << "\n";

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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