/**
*    author:  lazyhash(yashkundu)
*    created: 09 Dec, 2024 | 22:35:35
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll inf = (ll)1e18+10;
const int MAXN = (int)2e5 + 10;

int n;
ll k;
ll p[MAXN];
vector<int> a, b;
 

void init() {
    p[0] = 1;
    for(int i=1;i<MAXN;i++) {
        p[i] = min(inf, 2*p[i-1]);
    }
}

void solve() {
    cin >> n >> k;
    a.clear(); b.clear();



    for(int i=1;i<=n;i++) {
        if(p[n-i-1]<k) {
            k -= p[n-i-1];
            b.push_back(i);
        } else {
            a.push_back(i);
        }
    }

    if(k!=1) {
        cout << "-1\n";
        return;
    }

    for(int i=0;i<a.size();i++) cout << a[i] << " ";
    for(int i=b.size()-1;i>=0;i--) cout << b[i] << " ";
    cout << "\n";




}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
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