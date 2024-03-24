/**
*   author: lazyhash(yashkundu)
*   created: 16 Jul, 2023 | 14:56:10
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    string l, r;
    cin >> l >> r;
    vector<vector<int>> next(n+1, vector<int>(10, n));
    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<10;j++) next[i][j] = next[i+1][j];
        next[i][s[i]-'0'] = i;
    }

    int cur = -1;
    for(int i=0;i<m && cur<n;i++) {
        int a = l[i]-'0', b = r[i]-'0';
        assert(a<=b);
        int curMax = -1;
        for(int j=a;j<=b;j++) {
            curMax = max(curMax, next[cur+1][j]);
        }
        cur = curMax;
    }

    cout << ((cur==n)?"YES":"NO");
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/