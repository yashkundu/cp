/**
*    author:  lazyhash(yashkundu)
*    created: 23 Oct, 2024 | 20:14:36
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

int n;
vector<int> a;

int x;
 
void solve() {
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> x;

    sort(a.begin(), a.end());

    int sum = 0;
    for(int i=0;i<n;i++) sum += a[i];


    if(x>=a[n-1]) {
        cout << sum << "\n";
        return;
    }

    int last = x;
    int ind = 0;

    while(ind<n) {
        if(a[ind]<=2*last) {
            last = max(last, a[ind]);
            ind++;
        } else break;
    }

    if(ind>0) {
        sum = sum - last + x;
    }

    cout << sum << "\n";

    




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