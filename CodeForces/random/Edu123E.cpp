/**
*    author:  lazyhash(yashkundu)
*    created: 29 Sep, 2024 | 17:45:43
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
string s;
int k;


ll calc(string s) {
    int ind = -1;
    for(int i=0;i<k;i++) if(s[i]=='R') {
        ind = i;
        break;
    }

    ll res = (n-1)*ind;

    ll y = 0;

    for(int i=k-1;i>=ind;i--) {
        if(s[i]=='D') res += y;
        else y++;
    }

    return res;
}

 
void solve() {
    cin >> n;
    cin >> s;
    k = s.size();

    
    bool b = true;
    for(int i=1;i<k;i++) if(s[i]!=s[0]) b = false;

    if(b) {
        cout << n << "\n";
        return;
    }

    ll ans = n*n;

    ans -= calc(s);

    for(int i=0;i<k;i++) {
        if(s[i]=='R') s[i] = 'D';
        else s[i] = 'R';
    }

    ans -= calc(s);

    cout << ans << "\n";
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