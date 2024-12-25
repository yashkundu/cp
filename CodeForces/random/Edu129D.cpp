/**
*    author:  lazyhash(yashkundu)
*    created: 26 Aug, 2024 | 22:28:59
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
ll x;
map<ll, int> dis;
 
queue<ll> q;

void solve() {
    cin >> n >> x;
    q.push(x);
    dis[x] = 0;

    while(!q.empty()) {
        ll k = q.front();
        q.pop();
        string s = to_string(k);
        if(s.size()==n) {
            cout << dis[k] << "\n";
            return;
        }
        for(auto c: s) {
            if(c=='0' || c=='1') continue;
            ll w = k*int(c-'0');
            if(!dis.count(w)) {
                dis[w] = dis[k] + 1;
                q.push(w);
            }
        }
    }

    cout << "-1\n";

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