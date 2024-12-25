/**
*    author:  lazyhash(yashkundu)
*    created: 13 Jul, 2024 | 17:46:30
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5)+10;


ll L, R;
int l[MAXN], r[MAXN];

int n;

 
void solve() {
    cin >> n;
    L = 0; R = 0;
    for(int i=0;i<n;i++) {
        cin >> l[i] >> r[i];
        L += l[i];
        R += r[i];
    }

    if(L>0 || R<0) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";



    for(int i=0;i<n;i++) {
        
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/