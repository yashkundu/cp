/**
*    author:  lazyhash(yashkundu)
*    created: 05 Sep, 2024 | 22:19:54
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


int calc(int a, int b) {
    if(a>=2*b) return (a+1)/2;
    int ans = (a-b);
    a -= 2*ans;
    b -= ans;
    ans += (a+b+2)/3;
    return ans;
}


 
void solve() {

    cin >> n;
    a.resize(n);

    int x = (int)1e9, y = (int)1e9;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]<x) {
            y = x;
            x = a[i];
        } else if(a[i]<y) y = a[i];
    }


    int ans = (x+1)/2 + (y+1)/2;

    for(int i=0;i+2<n;i++) {
        ans = min(ans, (a[i]+1)/2 + (a[i+2]+1)/2);
        ans = min(ans, 1 + a[i]/2 + a[i+2]/2);
    }

    for(int i=0;i+1<n;i++) {
        ans = min(ans, calc(max(a[i], a[i+1]), min(a[i], a[i+1])));
    }

    cout << ans << "\n";






    

    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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