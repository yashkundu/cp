/**
*    author:  lazyhash(yashkundu)
*    created: 09 Jun, 2024 | 16:56:58
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;




const int N = 51;
ll k[N];
 
int n;
 
ll gcd(ll a, ll b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}


void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> k[i];

    ll den = 1;
    for(int i=0;i<n;i++) den = lcm(den, k[i]);

    ll suma = 0;
    for(int i=0;i<n;i++) suma += den/k[i];


    if(suma<den) {
        for(int i=0;i<n;i++) {
            cout << den/k[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
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