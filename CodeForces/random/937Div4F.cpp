/**
*    author:  lazyhash(yashkundu)
*    created: 19 Jun, 2024 | 16:48:36
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a, b, c;
 
void solve() {
    cin >> a >> b >> c;
    if(a+1!=c) {
        cout << "-1\n";
        return;
    }
    if(a==0) {
        cout << b << "\n";
        return;
    }

    int curDep = 32 - __builtin_clz(a);
    int left = (1<<curDep) - 1 - a;
    b = max(0, b-left);
    int del = 2*(a - ((1<<(curDep-1))-1)) + left;
    curDep += (b+del-1)/del;

    cout << curDep << "\n";



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