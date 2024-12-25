/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jun, 2024 | 20:32:57
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5+10;
int A[MAXN], B[MAXN];

int n;
 
void solve() {
    cin >> n;

    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<n;i++) cin >> B[i];

    int a = 0, b = 0;
    int good = 0, bad = 0;

    for(int i=0;i<n;i++) {
        if(A[i]==B[i]) {
            if(A[i]==1) good++;
            else if(A[i]==-1) bad++;
        } else {
            if(A[i]>0) a++;
            else if(B[i]>0) b++;
        }
    }


    for(int i=0;i<good;i++) {
        if(a<b) a++;
        else b++;
    } 

    for(int i=0;i<bad;i++) {
        if(a>b) a--;
        else b--;
    }

    cout << min(a, b) << "\n";


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