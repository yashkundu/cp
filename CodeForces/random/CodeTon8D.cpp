/**
*    author:  lazyhash(yashkundu)
*    created: 21 Jun, 2024 | 14:22:41
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

const int MAXN = 1e3+2;

vector<int> dp[MAXN];
int a[MAXN][MAXN]={0};

int n, k;

priority_queue<pair<int, pair<int, int>>> pq;
 
void solve() {
    cin >> n >> k;
    for(int i=0;i<=n+1;i++) dp[i].clear();
    dp[0].push_back({0});

    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) cin >> a[i][j];
    }


    for(int i=1;i<=n+1;i++) {
        // dp[i] -> ith index is not painted
        // dp[i-1], dp[i-2], dp[i-3], dp[i-4]
        for(int j=i-1;j>=0;j--) {
            pq.push({dp[j][0]+a[j+1][i-1], {j, 1}});
        }
        for(int num=0;num<k && !pq.empty();num++) {
            auto p = pq.top();
            pq.pop();
            dp[i].push_back(p.first);
            if(p.second.second<dp[p.second.first].size()) {
                pq.push({dp[p.second.first][p.second.second]+a[p.second.first+1][i-1], {p.second.first, p.second.second+1}});
            }
        }
        while(!pq.empty()) pq.pop();
    }


    for(int x: dp[n+1]) cout << x << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/