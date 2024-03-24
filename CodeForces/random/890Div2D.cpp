/**
*   author: lazyhash(yashkundu)
*   created: 22 Feb, 2024 | 22:39:51
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int query(int l, int r) {
    if(l==r) return 0;
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}


int find_max(int l, int r) {
    if(l==r) return l;
    int mid = (l+r)/2;
    int ind1 = find_max(l, mid);
    int ind2 = find_max(mid+1, r);
    // merge those two results into bigger one
    if(query(l, ind2)>query(l, ind2-1)) return ind1;
    return ind2;
}


 
void solve() {
    int n;
    cin >> n;
    int ind = find_max(1, n);
    cout << "! " << ind << endl;
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