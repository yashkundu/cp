/**
*    author:  lazyhash(yashkundu)
*    created: 06 Jul, 2024 | 18:04:46
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int n;
string s, t;


int dis[(1<<16)][16];


pair<int, int> convert(string s) {
    int mask = 0;
    for(int i=0;i<n;i++) {
        if(s[n-i-1]=='W') mask += (1<<(i+2));
    }
    return {mask, 1};
}


int trans(int mask, int prv, int nw) {
    int b1 = (mask>>nw)&1;
    int b2 = (mask>>(nw-1))&1;
    mask ^= (b1<<nw);
    mask ^= (b2<<(nw-1));
    mask ^= (b1<<prv);
    mask ^= (b2<<(prv-1));
    return mask;
}



void solve() {
    cin >> n;
    cin >> s >> t;

    for(int i=0;i<(1<<(n+2));i++) for(int j=0;j<=n+1;j++) dis[i][j] = -1;
    
    auto p = convert(s);
    dis[p.first][p.second] = 0;


    queue<pair<int, int>> q;
    q.push(p);

    while(!q.empty()) {
        auto p = q.front(); q.pop();
        for(int i=p.second+2;i<=n+1;i++) {
            int mask = trans(p.first, p.second, i);
            if(dis[mask][i]==-1) {
                dis[mask][i] = 1 + dis[p.first][p.second];
                q.push({mask, i});
            }
        }

        for(int i=p.second-2;i>0;i--) {
            int mask = trans(p.first, p.second, i);
            if(dis[mask][i]==-1) {
                dis[mask][i] = 1 + dis[p.first][p.second];
                q.push({mask, i});
            }
        }
    }

    auto p2 = convert(t);
    int ans = dis[p2.first][p2.second];
    cout << ans << "\n";




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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/