/**
*    author:  lazyhash(yashkundu)
*    created: 18 Jun, 2024 | 16:00:58
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cnt[5], tCnt[5];
 
void solve() {
    cin >> cnt[1] >> cnt[2] >> cnt[3] >> cnt[4];
    
    int ans = 0;
    int curAns = 0;

    for(int mask=0;mask<(1<<4);mask++) {
        for(int j=1;j<5;j++) tCnt[j] = cnt[j];
        curAns = 0;
        bool bad = false;
        for(int j=0;j<4;j++) {
            if((mask>>j)&1) {
                tCnt[j+1]--;
                if(tCnt[j+1]<0) bad = true;
            }
        }
        if(bad) continue;
        int x = 0;
        for(int j=1;j<5;j++) if(tCnt[j]&1) x ^= j;
        if(x) continue;
        if(tCnt[1]+tCnt[2]+tCnt[3]+tCnt[4]==0) continue;
        curAns = 1;
        bool isOdd = false;
        for(int j=1;j<5;j++) {
            curAns += tCnt[j]/2;
            if(tCnt[j]&1) isOdd = true;
        }
        if(!isOdd) curAns--;
        ans = max(ans, curAns);
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