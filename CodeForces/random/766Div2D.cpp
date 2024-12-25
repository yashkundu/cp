/**
*    author:  lazyhash(yashkundu)
*    created: 07 Oct, 2024 | 20:00:36
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)1e6+10;

bool a[MAXN] = {0};
ll cnt[MAXN] = {0};

int n;
int x;
 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x;
        a[x] = 1;
    }

    for(int i=1000000;i>=1;i--) {
        int num = 0;
        for(int j=i;j<MAXN;j+=i) if(a[j]) num++;
        cnt[i] = 1LL*num*(num-1)/2;
        for(int j=2*i;j<MAXN;j+=i) cnt[i] -= cnt[j];
        if(cnt[i] && !a[i]) {
            a[i] = 1;
            cnt[i] += num;
        }
    }

    int tot = 0;
    for(int i=1;i<MAXN;i++) if(a[i]) tot++;

    cout << (tot-n) << "\n";

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