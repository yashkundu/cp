/**
*   author: lazyhash(yashkundu)
*   created: 11 Sep, 2023 | 22:03:10
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    int maxOnlineSubs = a;
    int totAddQueries = a;
    int cur = a;

    for(char ch: s) {
        if(ch=='+') {
            cur++;
            totAddQueries++;
            maxOnlineSubs = max(maxOnlineSubs, cur);
        } else {
            cur--;
        }
    }

    if(maxOnlineSubs==n) {
        cout << "YES\n";
    } else if(totAddQueries<n) {
        cout << "NO\n";
    } else {
        cout << "MAYBE\n";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/