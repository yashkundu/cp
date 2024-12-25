/**
*    author:  lazyhash(yashkundu)
*    created: 08 Dec, 2024 | 17:32:05
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

int n;
ll k;
string s;

vector<ll> v;
 
void solve() {
    cin >> n >> k;
    cin >> s;

    v.clear();
    ll cur = 0;


    for(int i=n-1;i>0;i--) {
        if(s[i]=='1') cur++;
        else cur--;
        v.push_back(cur);
    }

    sort(v.rbegin(), v.rend());

    int ans = -1;


    cur = 0;
    for(int i=0;i<n-1;i++) {
        cur += v[i];
        if(cur>=k) {
            ans = (i+2);
            break;
        }
    }

    cout << ans << "\n";



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