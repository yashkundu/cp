/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jan, 2023 | 15:01:09
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int query(int x) {
    cout << "- " << x << endl;
    int y;
    cin >> y;
    return y;
}
 
void solve() {
    int pre;
    cin >> pre;

    int x = 1;
    int num = 1;
    int cur = 0;
    int q;
    while(q=query(x)) {
        int del = q-pre+1;
        cur += del;
        if(cur==q) {
            x = (1<<cur) - 1;
        } else {
            x = (1<<cur);
        }
        num += x;
        pre = q;
    }

    cout << "! " << num << endl;

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