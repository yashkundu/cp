/**
*    author:  lazyhash(yashkundu)
*    created: 23 Jun, 2024 | 14:01:25
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e6+10;

map<int, vector<pair<int, int>>> events;
multiset<int> ms;

int dp[MAXN];



int n, m;
int l, r;

 
void solve() {
    cin >> n >> m;
    for(int i=0;i<=n;i++) dp[i] = 0;
    for(int i=0;i<=n+1;i++) events[i].clear();
    ms.clear();


    for(int i=0;i<m;i++) {
        cin >> l >> r;
        events[l].push_back({1, r});
        events[r+1].push_back({-1, r});
    }



    for(int i=1;i<=n;i++) {
        for(auto [t, x]: events[i]) {
            if(t==1) ms.insert(x);
            else ms.extract(x);
        }
        dp[i] = max(dp[i], dp[i-1]);
        if(!ms.empty()) {
            int largest = *ms.rbegin();
            dp[largest] = max(dp[largest], dp[i-1]+(int)ms.size());
        }
    }


    cout << dp[n] << "\n";




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