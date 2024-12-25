/**
*    author:  lazyhash(yashkundu)
*    created: 26 Sep, 2024 | 20:45:20
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)2e5+10;
int n, d;

int a[MAXN];

vector<int> bad;



bool checkInd(int x, int ind) {
    if(ind<n && a[ind+1]-a[ind-1]-1<x) return false;
    for(int i=1;i<ind;i++) if(a[i]-a[i-1]-1>=2*x+1) return true;
    if(ind<n && a[ind+1]-a[ind-1]-1>=2*x+1) return true;
    for(int i=ind+2;i<=n;i++) if(a[i]-a[i-1]-1>=2*x+1) return true;
    if(ind==n && d-a[n-1]>=x+1) return true;
    if(ind!=n && d-a[n]>=x+1) return true; 
    return false;
}




bool check(int x) {
    bad.clear();
    for(int i=1;i<=n;i++) {
        if(a[i]-a[i-1]-1<x) bad.push_back(i);
    }
    if(bad.empty()) return true;
    if(bad.size()>2) return false;
    if(bad.size()==2) {
        if(bad[0]+1!=bad[1]) return false;
        if(checkInd(x, bad[0])) return true;
        return false;
    } else {
        if(checkInd(x, bad[0])) return true;
        if(bad[0]>1 && checkInd(x, bad[0]-1)) return true;
        return false;
    }
}


 
void solve() {
    cin >> n >> d;
    a[0] = 0;

    for(int i=1;i<=n;i++) cin >> a[i];

    int L = 0, R = d;

    while(R-L>1) {
        int mid = (L+R)/2;
        if(check(mid)) L = mid;
        else R = mid;
    }

    cout << L << "\n";

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