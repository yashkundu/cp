/**
*    author:  lazyhash(yashkundu)
*    created: 26 Nov, 2024 | 20:54:26
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x;
    if(x==-1) exit(0);
    return x;
}

void output(int i) {
    cout << "! " << i << endl;
}
 
int n;

void solve() {
    cin >> n;

    for(int i=1;i<n;i+=2) {
        if(query(i, i+1)!=query(i+1, i)) {
            int other = 1;
            if(i==1) other = n;
            if(query(i, other)!=query(other, i)) output(i);
            else output(i+1);
            return;
        }
    }

    output(n);

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