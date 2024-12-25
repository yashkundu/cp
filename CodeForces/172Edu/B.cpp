/**
*    author:  lazyhash(yashkundu)
*    created: 02 Dec, 2024 | 20:21:05
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

int n;
int c;
 
void solve() {
    cin >> n;
    map<int, int> mp;

    for(int i=0;i<n;i++) {
        cin >> c;
        mp[c]++;
    }

    int cnt1 = 0;
    for(auto it: mp) {
        if(it.second==1) cnt1++;
    }

    int other = mp.size() - cnt1;


    int ans;
    if(cnt1) ans = ((cnt1+1)/2)*2 + other;
    else ans = other;

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