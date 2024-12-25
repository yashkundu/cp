/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jul, 2024 | 17:27:23
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

const int MAXN = int(2e5)+10;

int n, c;

vector<pair<int, int>> v;
int a[MAXN];
int inds[MAXN];
ll psum[MAXN];

int ans = 0;

 
void solve() {
    cin >> n >> c;
    v.clear();

    for(int i=1;i<=n;i++) {
        cin >> a[i];
        v.push_back({min(a[i]+i, a[i]+n+1-i), i});
    }


    sort(v.begin(), v.end());

    for(int i=0;i<n;i++) {
        inds[v[i].second] = i;
    }

    psum[0] = 0;
    for(int i=1;i<=n;i++) {
        psum[i] = psum[i-1] + v[i-1].first;
    }

    ans = 0;
    for(int i=1;i<=n;i++) {
        int incost = a[i]+i;
        if(c<incost) continue;
        int ind = upper_bound(psum, psum+n+1, c-incost) - psum;
        ind--;
        if(inds[i]+1>ind) {
            ans = max(ans, 1+ind);
        } else {
            ans = max(ans, 1+ind-1);
            if(ind<n && psum[ind]-v[inds[i]].first+v[ind].first<=c-incost) ans = max(ans, 1+ind);
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