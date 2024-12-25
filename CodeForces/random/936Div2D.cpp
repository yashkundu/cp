/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jun, 2024 | 14:00:57
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e5+10;

int n, x;
vector<int> a;
 
void solve() {
    cin >> n >> x;
    x++;
    a.resize(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }


    int res = -1;
    for(int j=30;j>=0;j--) {
        vector<int> b;
        bool open = false;
        for(int i=0;i<a.size();i++) {
            if(!open) b.push_back(a[i]);
            else b.back() ^= a[i];
            if(a[i]&(1<<j)) open = !open;
        }
        if(!(x&(1<<j))) {
            if(open) {
                cout << res << "\n";
                return;
            } 
            a = b;
        } else {
            if(!open) res = max(res, (int)b.size());
        }
    }

    cout << res << "\n";

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