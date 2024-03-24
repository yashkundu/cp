/**
*   author: lazyhash(yashkundu)
*   created: 13 Nov, 2023 | 22:48:36
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
    int n, k;
    cin >> n >> k;
    int cnt[26] = {0};

    string s;
    cin >> s;
    for(int i=0;i<n;i++) {
        cnt[s[i]-'a']++;
    }

    int odd = 0;
    for(int i=0;i<26;i++) if(cnt[i]&1) odd++;

    if(k<odd-1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";


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