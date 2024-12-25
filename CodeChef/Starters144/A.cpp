/**
*    author:  lazyhash(yashkundu)
*    created: 24 Jul, 2024 | 20:01:19
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

int n, x;
ll extra;
int ans = 0;

vector<int> v;

int a;
 
void solve() {
    cin >> n >> x;
    extra = 0;
    ans = 0;
    
    v.clear();

    for(int i=0;i<n;i++) {
        cin >> a;
        if(a>=x) {
            ans++;
            extra += (a-x);
        } else {
            v.push_back(a);
        }
    }

    sort(v.rbegin(), v.rend());

    for(int i=0;i<v.size();i++) {
        if(extra>=x-v[i]) {
            ans++;
            extra -= (x-v[i]);
        } else break;
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