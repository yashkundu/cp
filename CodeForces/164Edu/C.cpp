/**
*   author: lazyhash(yashkundu)
*   created: 12 Apr, 2024 | 20:25:46
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
    string x, y;
    cin >> x >> y;

    int n = x.size();


    int diffInd = -1;
    for(int i=0;i<n;i++) {
        if(x[i]!=y[i]) {
            diffInd = i;
            break;
        }
    }

    if(diffInd==-1) {
        cout << x << "\n";
        cout << y << "\n";
        return;
    }

    bool firstBigger = x[diffInd]>y[diffInd];

    for(int i=diffInd+1;i<n;i++) {
        if((firstBigger && x[i]>y[i]) || (!firstBigger && x[i]<y[i])) swap(x[i], y[i]); 
    }

    cout << x << "\n";
    cout << y << "\n";




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