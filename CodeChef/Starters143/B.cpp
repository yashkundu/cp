/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jul, 2024 | 20:31:56
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


const int MAXN = int(2e5)+10;

vector<int> divs[MAXN];
int ans[MAXN];

void init() {
    for(int i=1;i<MAXN;i++) {
        for(int j=2*i;j<MAXN;j+=i) divs[j].push_back(i); 
    }


    ans[1] = 1;
    vector<int> v;
    for(int i=2;i<MAXN;i++) {
        v.clear();
        for(int d: divs[i]) v.push_back(ans[d]);
        sort(v.begin(), v.end());
        int val = 1;
        for(int x: v) {
            if(val==x) val++;
        }
        ans[i] = val;
    }

}

int n;

 
void solve() {
    cin >> n;
    int mx = 1;
    for(int i=1;i<=n;i++) mx = max(mx, ans[i]);

    cout << mx << "\n";
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
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