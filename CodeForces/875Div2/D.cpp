/**
*   author: lazyhash(yashkundu)
*   created: 30 May, 2023 | 23:12:47
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int S = 700;

int cnt1[N] = {0}, cnt2[2*N]={0};
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt1[a[i]]++;
    }

    for(int i=0;i<n;i++) {
        cin >> b[i];
    }



    for(int i=0;i<=n;i++) cnt1[i] = 0;
    for(int i=0;i<=2*n;i++) cnt2[i] = 0;

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