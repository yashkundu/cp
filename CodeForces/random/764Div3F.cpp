/**
*    author:  lazyhash(yashkundu)
*    created: 08 Oct, 2024 | 23:55:39
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int query(int c) {
    cout << "+ " << c << endl;
    int r;
    cin >> r;
    return r;
}

void output(int x) {
    cout << "! " << x << endl;
}

int n;
int prv, cur;
 
void solve() {
    cin >> n;
    int l = 0, r = n-1;

    prv = 0;


    while(r-l>0) {
        int mid = (l+r+1)/2;
        int del = (n-mid);
        cur = query(del);
        if(cur==prv) {
            l += del;
            r = mid - 1 + del;
        } else {
            l = (mid+del)%n;
            r = (r+del)%n;
        }
        prv = cur;
    }



    output(prv*n+l);



    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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