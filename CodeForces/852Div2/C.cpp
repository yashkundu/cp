/**
*    author:  lazyhash(yashkundu)
*    created: 18 Feb, 2023 | 15:25:42
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) {
        cin >> x;
        x--;
    }

    vector<bool> cnt(n, true);
    int mn = 0, mx = n-1;

    auto update_min = [&] () {
        while(mn<n && !cnt[mn]) mn++;
    };

    auto update_max = [&] () {
        while(mx>=0 && !cnt[mx]) mx--;
    };

    int l = 0, r = n-1;

    while(l<=r) {
        if(a[l]==mn || a[l]==mx) {
            cnt[a[l]] = false;
            l++;
            update_max(), update_min();
        }
        else if(a[r]==mn || a[r]==mx) {
            cnt[a[r]] = false;
            r--;
            update_max(), update_min();
        }
        else break;
    }

    if(l>r) cout << "-1\n";
    else cout << (l+1) << " " << (r+1) << "\n";




        
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