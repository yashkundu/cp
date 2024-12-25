/**
*    author:  lazyhash(yashkundu)
*    created: 25 Jun, 2024 | 20:50:57
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MAXN = 505;
ll a[MAXN][MAXN];
int pref[MAXN][MAXN];

int n, m, k;
string s;

ll suma = 0, sumb = 0;
ll del = 0;

set<int> st;

int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}


void solve() {
    cin >> n >> m >> k;
    st.clear();

    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) pref[i][j] = 0;
    suma = 0;
    sumb = 0;


    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }

    for(int i=1;i<=n;i++) {
        cin >> s;
        for(int j=0;j<m;j++) {
            pref[i][j+1] = s[j]=='1';
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(pref[i][j]) suma += a[i][j];
            else sumb += a[i][j];
        }
    }

    del = abs(suma-sumb);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }



    for(int i=1;i+k-1<=n;i++) {
        for(int j=1;j+k-1<=m;j++) {
            int x = pref[i+k-1][j+k-1] - pref[i-1][j+k-1] - pref[i+k-1][j-1] + pref[i-1][j-1];
            int diff = abs(k*k-x-x);
            if(diff) st.insert(diff);
        }
    }

    if(!del) {
        cout << "YES\n";
        return;
    }

    if(del && st.empty()) {
        cout << "NO\n";
        return;
    }

    int g = 0;
    for(int x: st) g = gcd(g, x);

    if(del%g!=0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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