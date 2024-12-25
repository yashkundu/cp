/**
*    author:  lazyhash(yashkundu)
*    created: 04 Aug, 2024 | 20:13:31
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a, odds, evens;
 
void solve() {
    cin >> n;
    a.resize(n);

    odds.clear(); evens.clear();

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]&1) odds.push_back(a[i]);
        else evens.push_back(a[i]);
    }

    if(odds.empty() || evens.empty()) {
        cout << "0\n";
        return;
    }

    ll mx = 0;
    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());

    mx = odds.back();
    int cnt = (int)evens.size();


    for(auto x: evens) {
        if(mx<x) {
            cnt++;
            break;
        }
        mx += x;
    }
    

    cout << cnt << "\n";


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