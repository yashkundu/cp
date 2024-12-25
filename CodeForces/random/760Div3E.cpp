/**
*    author:  lazyhash(yashkundu)
*    created: 12 Oct, 2024 | 17:47:29
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
vector<ll> a, b;

 
void solve() {
    cin >> n;
    a.resize(n);
    b.resize(n);

    ll sum = 0;

    for(int i=0;i<n;i++) {
        cin >> b[i];
        sum += b[i];
    }

    ll del = 1LL*n*(n+1)/2;
    if(sum%del) {
        cout << "NO\n";
        return;
    }

    sum /= del;

    for(int i=0;i<n;i++) {
        ll diff = b[i] - (i==0?b[n-1]:b[i-1]);
        diff = sum - diff;
        if(diff<=0 || diff%n!=0) {
            cout << "NO\n";
            return;
        }
        a[i] = diff/n;
    }



    cout << "YES\n";
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