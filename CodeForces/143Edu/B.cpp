/**
*   author: lazyhash(yashkundu)
*   created: 21 Feb, 2023 | 13:28:23
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> segs;

    for(int i=0;i<n;i++) {
        int l, r;
        cin >> l >> r;
        if(k>=l && k<=r) segs.push_back({l, r});
    }

    int cnt[55] = {0};

    for(auto seg: segs) {
        cnt[seg.first]++;
        cnt[seg.second+1]--;
    }

    for(int i=1;i<=50;i++) cnt[i] += cnt[i-1];

    for(int i=1;i<=50;i++) {
        if(i==k) continue;;
        if(cnt[i]>=cnt[k]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/