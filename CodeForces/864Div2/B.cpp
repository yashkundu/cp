/**
*   author: lazyhash(yashkundu)
*   created: 08 Apr, 2023 | 19:52:24
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<bool>> a(n, vector<bool>(n, 0));

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        int x;
        cin >> x;
        a[i][j] = x;
    }

    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(a[i][j] != a[n-i-1][n-j-1]) {
                a[i][j] = a[n-i-1][n-j-1];
                cnt++;
            }
        }
    }

    if(cnt>k) {
        cout << "No\n";
    } else if(cnt%2==k%2) {
        cout << "Yes\n";
    } else if(n%2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }


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