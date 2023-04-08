/**
*   author: lazyhash(yashkundu)
*   created: 26 Mar, 2023 | 20:07:53
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


bool check(vector<int> &a, vector<int> &b, int n) {
    int m1 = a[n-1], m2 = b[n-1];
    for(int i=n-2;i>=0;i--) {
        if(!(a[i]<=m1 && b[i]<=m2) && !(b[i]<=m1 && a[i]<=m2)) {
            return false;
        }
    }
    return true;
}

 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    if(check(a, b, n)) {
        cout << "Yes\n";
        return;
    }
    int tmp = b[n-1];
    b[n-1] = a[n-1];
    a[n-1] = tmp;
    if(check(a, b, n)) {
        cout << "Yes\n";
        return;
    }

    cout << "No\n";

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