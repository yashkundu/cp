/**
*    author:  lazyhash(yashkundu)
*    created: 22 Sep, 2024 | 22:37:12
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<pair<ll, int>> v;

ll a;
ll cur = 0;
int cnt = 0;



 
void solve() {
    cin >> n;
    v.clear();


    for(int i=0;i<n;i++) {
        cin >> a;
        if(v.empty()) {
            v.push_back({a, 1});
            continue;
        }
        cur = a;
        cnt = 1;
        while(!v.empty() && cur/cnt<=v.back().first) {
            auto p = v.back(); 
            v.pop_back();
            cur += p.first*p.second;
            cnt += p.second;
        }

        v.push_back({cur/cnt, cnt-cur%cnt});
        if(cur%cnt) v.push_back({cur/cnt+1, cur%cnt});
    }

    cout << v.back().first - v.front().first << "\n";



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