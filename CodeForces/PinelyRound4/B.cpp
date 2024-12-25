/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jul, 2024 | 20:11:38
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
vector<int> b;
vector<int> a;
 
void solve() {
    cin >> n;
    b.resize(n-1);

    for(int i=0;i<n-1;i++) cin >> b[i];

    a.resize(n);
    fill(a.begin(), a.end(), 0);


    for(int i=0;i<n-1;i++) {
        a[i] |= b[i];
        a[i+1] |= b[i];
    }


    for(int i=0;i<n-1;i++) {
        if(b[i]!=(a[i]&a[i+1])) {
            cout << "-1\n";
            return;
        }
    }

    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << "\n";



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