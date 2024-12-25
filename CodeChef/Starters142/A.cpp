/**
*    author:  lazyhash(yashkundu)
*    created: 10 Jul, 2024 | 20:02:08
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

int ans = 0;
int cur = 0;
int cur_or = 0;
 
void solve() {
    cin >> n;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];

    ans = n;

    
    for(int x=0;x<=30;x++) {
        cur = 0;
        cur_or = 0;
        for(int i=0;i<n;i++) {
            if((a[i]>>x)>0) cur++;
            else cur_or |= a[i];
        } 
        if(cur_or==((1<<x)-1)) ans = min(ans, cur);
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