/**
*   author: lazyhash(yashkundu)
*   created: 14 May, 2023 | 21:19:30
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <bitset>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

using bs = bitset<5000>;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int m, n;
    cin >> m >> n;

    bs initBs;
    for(int i=0;i<n;i++) initBs.set(i);
    vector<bs> cgb(n, initBs);

    vector<int> models(n);
    iota(models.begin(), models.end(), 0);


    vector<int> p(n);
    for(int &x: p) cin >> x;

    for(int j=0;j<m;j++) {
        vector<int> r(n);
        for(int i=0;i<n;i++) cin >> r[i];
        sort(models.begin(), models.end(), [&r](int i, int j) {
            return r[i]<r[j];
        });
        bs curBs;
        for(int i=0;i<n;) {
            int k = i;
            while(k<n && r[models[i]]==r[models[k]]) {
                cgb[models[k]] &= curBs;
                k++;
            }
            for(int j=i;j<k;j++) {
                curBs.set(models[j]);
            }
            i = k;
        }
    }

    vector<ll> dp(n);
    for(int i=0;i<n;i++) dp[i] = p[i];

    for(auto i : models) {
        for(int j=0;j<n;j++) {
            if(cgb[j][i]) {
                dp[j] = max(dp[j], dp[i] + p[j]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";


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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/