/**
*    author:  lazyhash(yashkundu)
*    created: 07 Jul, 2024 | 20:27:59
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
vector<int> a, b, c;
ll tot = 0;

int la, ra, lb, rb, lc, rc;


bool check(vector<int> &a, vector<int> &b, vector<int> &c) {
    ll suma = 0;
    int i = 0;

    for(i=0;i<n;i++) {
        suma += a[i];
        if(suma>=tot) break;
    }

    if(suma<tot) return false;

    ll sumc = 0;
    int j = n-1;
    for(j=n-1;j>=0;j--) {
        sumc += c[j];
        if(sumc>=tot) break;
    }

    if(sumc<tot) return false;

    ll sumb = 0;
    for(int k=i+1;k<j;k++) {
        sumb += b[k];
    }

    if(sumb<tot) return false;
    la = 1; ra = i+1; lb = i+2; rb = j; lc = j+1; rc = n;
    return true;
}


void output(int a, int b, int c, int x, int y, int z) {
    cout << a << " " << b << " " << c << " " << x << " " << y << " " << z << "\n";
}


 
void solve() {
    cin >> n;
    a.resize(n); b.resize(n), c.resize(n);

    tot = 0;


    for(int i=0;i<n;i++) {
        cin >> a[i];
        tot += a[i];
    }
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];

    tot = (tot+2)/3;

    if(check(a, b, c)) {
        output(la, ra, lb, rb, lc, rc);
    } else if(check(a, c, b)) {
        output(la, ra, lc, rc, lb, rb);
    } else if(check(b, a, c)) {
        output(lb, rb, la, ra, lc, rc);
    } else if(check(b, c, a)) {
        output(lc, rc, la, ra, lb, rb);
    } else if(check(c, a, b)) {
        output(lb, rb, lc, rc, la, ra);
    } else if(check(c, b, a)) {
        output(lc, rc, lb, rb, la, ra);
    }else {
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