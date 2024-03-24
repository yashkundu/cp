/**
*   author: lazyhash(yashkundu)
*   created: 06 Feb, 2024 | 23:34:41
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5+10;
const int LIM = 1e9+1;
int a[N];


ll lcm(int a, int b) {
    return (1LL*a*b/gcd(a, b));
}


int gcd(int a, int b) {
    return b==0?a:gcd(b, a%b);
}

 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];


    // iterate over r and find unique possible lcm
    // uniqLcms for all the segments ending at r, iterate over r
    set<int> uniqLcms;
    set<int> newUniqLcms;
    set<int> badLcms;

    for(int r=0;r<n;r++) {
        newUniqLcms.insert(a[r]);
        for(int prevLcm: uniqLcms) {
            // take new lcm, and check if it is <= 1e9, then add it
            ll newLcm = lcm(prevLcm, a[r]);
            if(newLcm<LIM) newUniqLcms.insert(int(newLcm));
        }
        uniqLcms = newUniqLcms;
        newUniqLcms.clear();
        for(int lcm: uniqLcms) badLcms.insert(lcm);
    }

    int goodLcm = 1;
    while(badLcms.count(goodLcm)) goodLcm++;

    cout << goodLcm << "\n";


    
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