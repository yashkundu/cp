/**
*    author:  lazyhash(yashkundu)
*    created: 14 Jun, 2024 | 13:43:27
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



int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    int x = a/gcd(a, b);
    if(x>((int)2e9)/b) return -1;
    return x*b;
}

set<int> st;


const int N = 2e3+10;
int a[N];
vector<int> divs;

int n;
 
void solve() {
    cin >> n;
    st.clear();
    divs.clear();
    int mx = 0;
    int l = 1;

    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n;i++) {
        st.insert(a[i]);
        mx = max(mx, a[i]);
        l = lcm(l, a[i]);
        if(l==-1) break;
    }

    if(l>mx || l==-1) {
        cout << n << "\n";
        return;
    }

    for(int i=1;i*i<=mx;i++) {
        if(mx%i) continue;
        if(st.find(i)==st.end()) divs.push_back(i);
        if(st.find(mx/i)==st.end()) divs.push_back(mx/i);
    }

    int ans = 0;
    int cnt = 0;
    for(int d: divs) {
        l = 1;
        cnt = 0;
        for(int i=0;i<n;i++) {
            if(d%a[i]!=0) continue;
            cnt++;
            l = lcm(l, a[i]);
        }
        if(l==d) ans = max(ans, cnt);
    }

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