/**
*    author:  lazyhash(yashkundu)
*    created: 13 Jun, 2024 | 20:17:13
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map> 

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, k;
map<int, pair<int, int>> mp;

const int N = 2e5+10;
bool good[N];

int r, c;
 
void solve() {
    cin >> n >> m >> k;

    for(int i=1;i<=k;i++) good[i] = false;
    mp.clear();

    for(int i=0;i<k;i++) {
        cin >> r >> c;
        if(mp.find(c)==mp.end()) mp[c] = {0, 0};
        mp[c] = max(mp[c], {r, i+1});
    }

    ll curH = n;
    ll lastCol = 1;

    ll ans = 0;

    for(auto p: mp) {
        ans += 1LL*curH*(p.first-lastCol);
        if(n-p.second.first<curH) {
            curH = n - p.second.first;
            good[p.second.second] = true;
        }
        lastCol = p.first;
    }

    ans += 1LL*curH*(m+1-lastCol);

    cout << ans << "\n";
    for(int i=1;i<=k;i++) cout << (good[i]?"1":"0") << " ";
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