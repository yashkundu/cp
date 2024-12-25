/**
*    author:  lazyhash(yashkundu)
*    created: 14 Dec, 2024 | 00:10:57
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)1e5+10;

int n, q;
int a[MAXN];
int cnt[2*MAXN];
int ans[MAXN];

int x;
 
void solve() {
    cin >> n >> q;
    fill(cnt, cnt+2*n+1, 0);
    fill(ans, ans+n+1, -1);

    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i=1;i<=2*n;i++) cnt[i] += cnt[i-1];

    sort(a, a+n);


    auto countNum = [](int x, int val) {
        int tot = 0;
        int y = 0;
        while(y<=n) {
            tot += cnt[y+val];
            if(y) tot -= cnt[y-1];
            y += x;
        }
        return tot;
    };

    while(q--) {
        cin >> x;
        if(ans[x]!=-1) {
            cout << ans[x] << " ";
            continue;
        }
        int L = -1, R = x-1;
        while(R-L>1) {
            int mid = (L+R)/2;
            if(countNum(x, mid)>=(n+2)/2) R = mid;
            else L = mid;
        }
        ans[x] = R;
        cout << ans[x] << " ";
    }

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