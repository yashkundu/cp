/**
*   author: lazyhash(yashkundu)
*   created: 12 Jun, 2023 | 20:42:56
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
    string s;
    cin >> s;

    int n = s.size();

    vector<vector<int>> pCnt(n+1, vector<int>(5, 0)), sCnt(n+1, vector<int>(5, 0));

    for(int i=0;i<n;i++) {
        for(int j=0;j<5;j++) pCnt[i+1][j] = pCnt[i][j];
        pCnt[i+1][s[i]-'A']++;
    }

    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<5;j++) sCnt[i][j] = sCnt[i+1][j];
        sCnt[i][s[i]-'A']++;
    }


    auto calcVal = [&pCnt, &sCnt](int k, int ind) {
        
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