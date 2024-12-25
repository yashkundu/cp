/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jul, 2024 | 20:24:29
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a;

vector<int> ops;
 
void solve() {

    cin >> n;
    a.resize(n);

    int mx = -1;
    int mn = int(1e9)+10;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    int p = a[0]&1;
    for(int i=0;i<n;i++) {
        if(a[i]%2!=p) {
            cout << "-1\n";
            return;
        }
    }

    ops.clear();


    while(mn<mx) {
        int mid = (mn+mx)/2;
        ops.push_back(mid);
        mx = -1;
        mn = int(1e9)+10;
        for(int i=0;i<n;i++) {
            a[i] = abs(a[i]-mid);
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
    }

    ops.push_back(mn);

    cout << ops.size() << "\n";

    for(int x: ops) cout << x << " ";
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