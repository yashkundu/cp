/**
*    author:  lazyhash(yashkundu)
*    created: 20 Oct, 2024 | 15:15:49
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
vector<pair<int, int>> a;
 
void solve() {
    cin >> n;
    a.resize(n);

    for(int i=0;i<n;i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        if(min(p1.first, p1.second)!=min(p2.first, p2.second)) {
            return min(p1.first, p1.second) < min(p2.first, p2.second);
        }
        return max(p1.first, p1.second) < max(p2.first, p2.second);
    });


    for(auto p: a) {
        cout << p.first << " " << p.second << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/