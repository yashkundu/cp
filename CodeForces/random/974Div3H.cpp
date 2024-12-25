/**
*    author:  lazyhash(yashkundu)
*    created: 02 Dec, 2024 | 00:19:20
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


const int MAXN = (int)2e5+10;

int n, q;
pair<int, int> hsh[MAXN];

int a;

int l, r;

 
void solve() {
    cin >> n >> q;
    map<int, pair<int, int>> mp;

    hsh[0] = {0, 0};
    for(int i=1;i<=n;i++) {
        cin >> a;
        if(!mp.count(a)) mp[a] = {rng(), rng()};
        hsh[i].first = hsh[i-1].first^mp[a].first;
        hsh[i].second = hsh[i-1].second^mp[a].second;
    }


    for(int i=0;i<q;i++) {
        cin >> l >> r;
        l--;
        if(hsh[l]==hsh[r]) cout << "YES\n";
        else cout << "NO\n";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/