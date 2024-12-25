/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jun, 2024 | 18:51:11
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


vector<pair<ll, int>> v;

int n;
ll h;
ll sum = 0;


void update(ll x) {
    int cnt = 0;
    while(!v.empty() && v.back().first<=x) {
        auto p = v.back();
        sum -= p.first*p.second;
        v.pop_back();
        cnt += p.second;
    }
    sum += x*(cnt+1);
    v.push_back({x, cnt+1});
}


 
void solve() {
    cin >> n;
    sum = 0;

    for(int i=0;i<n;i++) {
        cin >> h;
        update(h);
        cout << sum+1 << " ";
    }

    
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