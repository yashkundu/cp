/**
*    author:  lazyhash(yashkundu)
*    created: 31 Aug, 2024 | 21:04:43
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


    int ops = 0, segs = 0;
    int prev = -1;

    for(int i=0;i<n;i+=2) {
        if(s[i]!=s[i+1]) ops++;
        else {
            if(prev!=s[i]) segs++;
            prev = s[i];
        }
    }

    segs = max(segs, 1);

    cout << ops << " " << segs << "\n";

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