/**
*   author: lazyhash(yashkundu)
*   created: 04 May, 2024 | 14:42:06
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());





int n, k;


int xop(int a, int b) {
    // a - b
    int ans = 0;
    int f = 1;
    for(int j=0;j<18;j++) {
        int a1 = a%k;
        int b1 = b%k;
        ans += ((a1-b1+k)%k)*f;
        a /= k;
        b /= k;
        if(!a && !b) break;
        f = f*k;
    }
    return ans;
}

int query(int x) {
    cout << x << endl;
    int y;
    cin >> y;
    return y;
}

 
void solve() {
    cin >> n >> k;

    for(int i=1;i<=n;i++) {
        int q = 0;
        if(i==1) q==0;
        else if(i%2==0) q = xop(i-2, i-1);
        else q = xop(i-1, i-2);
        int ans = query(q);
        if(ans==1) break;
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/