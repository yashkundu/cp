/**
*   author: lazyhash(yashkundu)
*   created: 01 Apr, 2023 | 10:46:42
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int N = 3e5+10;
vector<int> a(N);
vector<int> score(N);
// max no. of good subsegments that can be made by doing exactly one change dp[i...n-1]
vector<int> dp(N);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    score[n] = 0;

    for(int i=n-1;i>=0;i--) {
        int nxt = i+a[i]+1;
        if(nxt<=n && score[nxt]>=0) score[i] = 1 + score[nxt];
        else score[i] = -1;
    }

    int mx = 0;
    dp[n] = 0;

    for(int i=n-1;i>=0;i--) {
        dp[i] = 1 + mx;
        int nxt = i + a[i] + 1;
        if(nxt<=n) dp[i] = max(dp[i], 1+dp[nxt]);
        mx = max(mx, score[i]);
    }


    for(int i=0;i<n-1;i++) {
        if(score[i+1]==a[i]) {
            cout << "0 ";
        } else if(score[i+1]>0) {
            cout << "1 ";
        } else if(dp[i+1]>=a[i]) {
            cout << "1 ";
        } else {
            cout << "2 ";
        } 
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