/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jul, 2024 | 20:15:43
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
vector<int> a;
vector<int> ta;
 
void solve() {
    cin >> n >> k;
    a.resize(n);
    fill(a.begin(), a.end(), 1);
    ta.clear();


    ll ans = 0;

    while(a.size()>1) {
        for(int i=0;i<a.size();i+=k) {
            ta.push_back(1);
            if(min(int(a.size())-1, i+k-1)>i)
                ans++;
        }
        swap(a, ta);
        ta.clear();
    }

    cout << ans << "\n";

    
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