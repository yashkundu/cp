/**
*    author:  lazyhash(yashkundu)
*    created: 28 Aug, 2024 | 20:10:25
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
string s;
 
void solve() {
    cin >> n;
    cin >> s;


    int cnt = 0;


    for(int i=0;i<n;) {
        int j = i;
        while(j<n && s[j]==s[i]) j++;
        if(j<n) cnt++;
        i = j;
    }

    int num = n - (cnt + 1);


    ll ans = 1LL*num*cnt + 1LL*cnt*(cnt-1)/2;

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