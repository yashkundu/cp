/**
*    author:  lazyhash(yashkundu)
*    created: 02 Dec, 2024 | 20:08:42
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

int n, k;
vector<int> a;
 
void solve() {
    cin >> n >> k;
    a.resize(n);

    int sum = 0;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    }


    if(sum<=k) {
        cout << (k-sum) << "\n";
        return;
    }

    sort(a.rbegin(), a.rend());

    sum = 0;
    for(int i=0;i<n;i++) {
        if(sum+a[i]==k) {
            cout << "0\n";
            return;
        } 
        if(sum+a[i]>k) {
            cout << (k-sum) << "\n";
            return;
        }
        sum += a[i];
    }

    





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