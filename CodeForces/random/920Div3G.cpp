/**
*   author: lazyhash(yashkundu)
*   created: 18 Feb, 2024 | 14:03:29
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


int n, m, k;
vector<vector<int>> a, st;
vector<vector<int>> dp, prefUp, prefDiag;


bool isInside(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

// returns the ans for the current orientation
int ans() {
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        prefUp[i][j] = a[i][j];
        if(isInside(i-1, j)) prefUp[i][j] += prefUp[i-1][j];
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        prefDiag[i][j] = a[i][j];
        if(isInside(i-1, j+1)) prefDiag[i][j] += prefDiag[i-1][j+1];
    }
    int curAns = 0;


    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        // [i, j]
        dp[i][j] = a[i][j];
        if(isInside(i-1, j)) dp[i][j] += prefUp[i-1][j];
        if(isInside(i-k-1, j)) dp[i][j] -= prefUp[i-k-1][j];
        if(isInside(i, j-1)) dp[i][j] += dp[i][j-1];
        int edgeJ = j-k-1;
        int edgeI = i;
        if(edgeJ<0) {
            edgeI += edgeJ;
            edgeJ = 0;
        }
        if(isInside(edgeI, edgeJ)) dp[i][j] -= prefDiag[edgeI][edgeJ];
        if(isInside(i-k-1, j)) dp[i][j] += prefDiag[i-k-1][j];
        curAns = max(curAns, dp[i][j]);
    }
    return curAns;
}

 
void solve() {
    cin >> n >> m >> k;

    a.resize(n), st.resize(n), dp.resize(n), prefUp.resize(n), prefDiag.resize(n);
    for(int i=0;i<n;i++) a[i].resize(m), st[i].resize(m), dp[i].resize(m), prefUp[i].resize(m), prefDiag[i].resize(m);

    string s;
    for(int i=0;i<n;i++) {
        cin >> s;
        for(int j=0;j<m;j++) a[i][j] = st[i][j] = (s[j]=='#');
    }

    int mxAnx = 0;
    mxAnx = ans();

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        a[i][j] = st[i][m-1-j];
    }

    mxAnx = max(mxAnx, ans());

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        a[i][j] = st[n-1-i][j];
    }
    mxAnx = max(mxAnx, ans());

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        a[i][j] = st[n-1-i][m-1-j];
    }
    mxAnx = max(mxAnx, ans());

    cout << mxAnx << "\n";





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