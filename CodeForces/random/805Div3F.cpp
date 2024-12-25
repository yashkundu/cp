/**
*    author:  lazyhash(yashkundu)
*    created: 29 Jul, 2024 | 20:23:44
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

int n;
vector<int> a, b;
 
map<int, int> mp;

void solve() {
    cin >> n;

    a.resize(n), b.resize(n);
    mp.clear();

    for(int i=0;i<n;i++) {
        cin >> a[i];
        while(a[i]%2==0) a[i] /= 2;
        mp[a[i]]++;
    }

    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=0;i<n;i++) {
        while(b[i]>0) {
            if(mp[b[i]]) {
                mp[b[i]]--;
                break;
            }
            b[i] /= 2;
        }
        if(!b[i]) { 
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";


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