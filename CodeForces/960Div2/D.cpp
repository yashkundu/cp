/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jul, 2024 | 21:05:25
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a;

int ops = 0;
 
void solve() {
    cin >> n;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];

    int prv = 0;
    ops = 0;

    for(int i=0;i<n;i++) {
        // a[i]
        if(!a[i]) {
            prv = 0;
            continue;
        }

        if(prv==0) {
            ops++;
            if(a[i]<=2) prv = 1;
            else prv = 0;
            continue;
        }

        if(prv==1) {
            if(a[i]<=2) prv = 0;
            else {
                ops++;
                if(a[i]<=4) prv = 2;
                else prv = 0;
            }
            continue;
        }

        if(prv==2) {
            ops++;
            if(a[i]>4) prv = 0;
            else prv = 1;
        }
    }

    cout << ops << "\n";


    
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