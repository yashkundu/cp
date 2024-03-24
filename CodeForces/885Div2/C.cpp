/**
*   author: lazyhash(yashkundu)
*   created: 23 Jul, 2023 | 16:02:49
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int calc(int a, int b) {
    assert(!(a==b && a==0));
    if(a==b) return 2;
    if(a==0) return 0;
    if(b==0) return 1;
    // can take any number of steps which are multiple of three without worrying
    if (a<b) {
        return 1 + calc(b, b-a);
    }
    if(2*b>a) {
        return 1 + calc(b, a-b);
    }
    return 1 + calc(b, abs(a - (a-1)/(2*b)*2*b) - b);
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    int x = -1;
    bool isDull = true;
    for(int i=0;i<n;i++) {
        if(a[i]==b[i] && a[i]==0) continue;
        if(x==-1) {
            x = calc(a[i], b[i])%3;
        } else if(x != calc(a[i], b[i])%3){
            isDull = false;
        }
    }

    cout << (isDull?"YES":"NO") << "\n";

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