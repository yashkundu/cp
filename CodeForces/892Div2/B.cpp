/**
*   author: lazyhash(yashkundu)
*   created: 31 Aug, 2023 | 22:59:47
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int inf = 1e9+10;
 
void solve() {
    int n;
    cin >> n;
    
    ll tot = 0;
    int firstMin = inf, secondMin = inf;

    for(int i=0;i<n;i++) {
        int m;
        cin >>m;
        int min1 = inf, min2 = inf;
        for(int j=0;j<m;j++) {
            int x;
            cin >>x;
            if(x<min1) {
                min2 = min1;
                min1 = x;
            } else if (x<min2) {
                min2 = x;
            }
        }
        tot += min2;
        firstMin = min(firstMin, min1);
        secondMin = min(secondMin, min2);
    }
    tot = tot - secondMin + firstMin;
    cout << tot << "\n";



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