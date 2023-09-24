/**
*   author: lazyhash(yashkundu)
*   created: 27 Apr, 2023 | 20:16:16
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;


 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;


set<int> s[N];
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int &x: p) cin >> x;
    vector<int> v(n);

    for(int i=0;i<k;i++) s[i].clear();
    for(int i=0;i<n;i++) s[i%k].insert(i+1);

    int var = 0;

    for(int i=0;i<n;i++) {
        if(!s[i%k].count(p[i])) {
            var++;
        }
    }

    if(var==0) {
        cout << "0";
    } else if(var==2) {
        cout << "1";
    } else {
        cout << "-1";
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