/**
*   author: lazyhash(yashkundu)
*   created: 10 Mar, 2023 | 16:28:03
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 110;
vector<int> cnt(N, 0);
 
void solve() {
    int n;
    cin >> n;
    fill(cnt.begin(), cnt.begin()+n+1, 0);
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        cnt[abs(x)]++;
    }

    int c1 = 0, c2 = 0;
    for(int i=1;i<=n;i++) {
        c1 += cnt[i]==1;
        c2 += cnt[i]==2;
    }

    for(int i=1;i<=n;i++) {
        int cur = (i<=c1+c2?i:2*c1+2*c2-i);
        cout << cur << " ";
    }
    cout << "\n";

    for(int i=1;i<=n;i++) cout << (i<=2*c2?i&1:i-2*c2) << " ";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/