/**
*   author: lazyhash(yashkundu)
*   created: 31 Aug, 2023 | 09:36:16
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
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<int> b, c;
    int mx = 0, mxCnt = 0;
    for(int x: a) {
        if(x>mx) {
            mx = x;
            mxCnt = 1;
        } else if(x==mx) mxCnt++;
    }

    if(mxCnt==n) {
        cout << "-1\n";
        return;
    }

    for(int x: a) 
        if(x==mx) c.push_back(x);
        else b.push_back(x);


    cout << b.size() << " " << c.size() << "\n";

    for(int x: b) cout << x << " ";
    cout << "\n";
    for(int x: c) cout << x << " ";
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