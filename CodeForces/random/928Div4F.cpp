/**
*   author: lazyhash(yashkundu)
*   created: 11 Apr, 2024 | 23:01:40
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


bool g[7][7];


vector<pair<int, int>> odds, evens;

void precompute() {
    for(int i=0;i<7;i++) for(int j=0;j<7;j++) 
        if((i+j)%2) odds.emplace_back(i, j); 
        else evens.emplace_back(i, j);
}


bool check(bool g[7][7], int parity) {
    for(int i=1;i<6;i++) for(int j=1;j<6;j++) {
        if((i+j)%2!=parity) continue;
        if(g[i][j] && g[i-1][j-1] && g[i-1][j+1] && g[i+1][j-1] && g[i+1][j+1]) return false;
    }
    return true;
}


bool calc(bool g[7][7], int flipsLeft, int idx, vector<pair<int, int>> &v, int parity) {
    if(flipsLeft==0) return check(g, parity);
    if(idx==v.size()) return false;
    bool ans = false;
    ans |= calc(g, flipsLeft, idx+1, v, parity);
    g[v[idx].first][v[idx].second] = !g[v[idx].first][v[idx].second];
    ans |= calc(g, flipsLeft-1, idx+1, v, parity);
    g[v[idx].first][v[idx].second] = !g[v[idx].first][v[idx].second];
    return ans;
}

 
void solve() {
    for(int i=0;i<7;i++) {
        string s;
        cin >> s;
        for(int j=0;j<7;j++) g[i][j] = (s[j]=='B');
    }


    int res = 0;
    for(int i=0;i<=4;i++) {
        if(calc(g, i, 0, evens, 0)) {
            res += i;
            break;
        }
    }

    for(int i=0;i<=4;i++) {
        if(calc(g, i, 0, odds, 1)) {
            res += i;
            break;
        }
    }

    cout << res << "\n";
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    precompute();
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