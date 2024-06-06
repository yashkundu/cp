/**
*   author: lazyhash(yashkundu)
*   created: 31 Mar, 2024 | 12:33:12
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
const int N = 2e5+10;

int avCol[N][4];
vector<int> sfCols;
vector<int> treasures[N];


// dp[i][j] min number of ways to reach ith row and jthe availble column on ith row
ll dp[N][4];
const ll inf = 1e18+10;



pair<int, int> getAdjCols(vector<int> &sfCols, int x) {
    auto it = lower_bound(sfCols.begin(), sfCols.end(), x);

    if(it==sfCols.end()) {
        it--;
        return {*it, *it};
    }

    if(*it==x || it==sfCols.begin()) {
        return {*it, *it};
    }
    int second = *it;
    it--;
    int first = *it;
    return {first, second};
}


 
void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    for(int i=0;i<n;i++) treasures[i].clear();
    sfCols.clear();

    for(int i=0;i<k;i++) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        treasures[r].push_back(c);
    }


    for(int i=0;i<q;i++) {
        int b;
        cin >> b;
        b--;
        sfCols.push_back(b);
    }


    sort(sfCols.begin(), sfCols.end());
    for(int i=0;i<n;i++) sort(treasures[i].begin(), treasures[i].end());

    avCol[0][0] = avCol[0][1] = avCol[0][2] = avCol[0][3] = 0;

    bool isFirstEmtpy = treasures[0].empty();

    if(isFirstEmtpy) {
        auto it = lower_bound(sfCols.begin(), sfCols.end(), 0);
        int c = *it;
        avCol[1][0] = avCol[1][1] = avCol[1][2] = avCol[1][3] = c;
    }


    for(int i=0;i<n;i++) {
        if(isFirstEmtpy && !i) continue;
        if(treasures[i].empty()) {
            for(int j=0;j<4;j++) avCol[i+1][j] = avCol[i][j];
        } else {
            int first = treasures[i][0], last = treasures[i].back();
            auto p = getAdjCols(sfCols, first);
            avCol[i+1][0] = p.first;
            avCol[i+1][1] = p.second;
            p = getAdjCols(sfCols, last);
            avCol[i+1][2] = p.first;
            avCol[i+1][3] = p.second;
        }
    }

    for(int i=0;i<n;i++) for(int j=0;j<4;j++) dp[i][j] = inf;
    for(int j=0;j<4;j++) dp[0][j] = 0;


   



    for(int i=0;i<n;i++) {
        if(treasures[i].empty()) {
            for(int j=0;j<4;j++) dp[i+1][j] = min(dp[i+1][j], 1 + abs(avCol[i][j] - avCol[i+1][j]) + dp[i][j]);
            continue;
        }
        for(int j=0;j<4;j++) {
            int c = avCol[i][j];
            // ending at first point
            int del = abs(c-treasures[i].back()) + abs(treasures[i][0] - treasures[i].back());
            dp[i+1][0] = min(dp[i+1][0], del + abs(avCol[i+1][0] - treasures[i][0]) + 1 + dp[i][j]);
            dp[i+1][1] = min(dp[i+1][1], del + abs(avCol[i+1][1] - treasures[i][0]) + 1 + dp[i][j]);

            // ending at last point
            del = abs(c - treasures[i][0]) + abs(treasures[i][0] - treasures[i].back());
            dp[i+1][2] = min(dp[i+1][2], del + abs(avCol[i+1][2] - treasures[i].back()) + 1 + dp[i][j]);
            dp[i+1][3] = min(dp[i+1][3], del + abs(avCol[i+1][3] - treasures[i].back()) + 1 + dp[i][j]);
        }
    }

    int lastInd = -1;
    for(int i=n-1;i>=0;i--) if(treasures[i].size()) {
        lastInd = i;
        break;
    }

    ll ans = inf;

    for(int j=0;j<4;j++) {
        ans = min(ans, dp[lastInd][j] + abs(avCol[lastInd][j] - treasures[lastInd][0]) + abs(treasures[lastInd][0] - treasures[lastInd].back()));
        ans = min(ans, dp[lastInd][j] + abs(avCol[lastInd][j] - treasures[lastInd].back()) + abs(treasures[lastInd][0] - treasures[lastInd].back()));
    }

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/