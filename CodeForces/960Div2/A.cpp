/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jul, 2024 | 20:12:11
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
int cnt[51];
 
void solve() {

    cin >> n;
    for(int i=1;i<=50;i++) cnt[i] = 0;
    a.resize(n);

    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i=1;i<=50;i++) {
        if(cnt[i]&1) {
            cout << "YES\n";
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