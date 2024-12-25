/**
*    author:  lazyhash(yashkundu)
*    created: 16 Nov, 2024 | 20:43:39
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
map<int, int> mp;

int h;
 
void solve() {
    cin >> n;
    mp.clear();


    for(int i=0;i<n;i++) {
        cin >> h;
        mp[h]++; 
    }

    int num = 0;
    for(auto [x, y]: mp) {
        num = max(num, y);
    }

    cout << n - num << "\n";


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