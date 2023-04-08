/**
*   author: lazyhash(yashkundu)
*   created: 02 Apr, 2023 | 20:10:44
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
    int n;
    cin >> n;
    string s;
    cin >> s;

    char min_char = 'z';
    for(int i=0;i<n;i++) {
        min_char = min(min_char, s[i]);
    }

    int ind = n-1;
    while(ind>0 && s[ind]!=min_char) ind--;

    cout << s[ind];
    for(int i=0;i<n;i++) {
        if(i==ind) continue;
        cout << s[i];
    }
    cout << "\n";

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