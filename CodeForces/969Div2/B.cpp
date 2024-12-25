/**
*    author:  lazyhash(yashkundu)
*    created: 30 Aug, 2024 | 20:20:41
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<int> a;
int l, r;
char ch;

int mx = 0;

void solve() {
    cin >> n >> m;
    a.resize(n);

    mx = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    for(int i=0;i<m;i++) {
        cin >> ch;
        cin >> l >> r;
        if(ch=='+') {
            if(mx>=l && mx<=r) mx++;
        } else {
            if(mx>=l && mx<=r) mx--;
        }
        cout << mx << " ";
    }

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/