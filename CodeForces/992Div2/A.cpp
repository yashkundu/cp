/**
*    author:  lazyhash(yashkundu)
*    created: 09 Dec, 2024 | 22:11:42
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
vector<int> a;

map<int, int> mp;
 
void solve() {
    cin >> n >> k;
    a.resize(n);
    mp.clear();


    for(int i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]%k]++;
    }

    for(int i=0;i<n;i++) {
        if(mp[a[i]%k]==1) {
            cout << "YES\n";
            cout << i+1<< "\n";
            return;
        }
    }

    cout << "NO\n";




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