/**
*   author: lazyhash(yashkundu)
*   created: 30 May, 2023 | 21:51:18
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 4e5+10;
int cntA[N] = {0};
int cntB[N] = {0};
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }

    auto cLenCalculator = [](vector<int> &v, int *cnt) {
        int n = v.size();
        for(int i=0;i<n;) {
            int j = i;
            while(j<n && v[j]==v[i]) j++;
            cnt[v[i]] = max(cnt[v[i]], j-i);
            i = j;
        }
    };

    cLenCalculator(a, cntA);
    cLenCalculator(b, cntB);

    int ans = 0;
    for(int x: a) ans = max(ans, cntA[x]+cntB[x]);
    for(int x: b) ans = max(ans, cntA[x]+cntB[x]);

    for(int x: a) cntA[x] = 0;
    for(int x: b) cntB[x] = 0;


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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/