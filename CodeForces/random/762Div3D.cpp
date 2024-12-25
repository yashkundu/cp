/**
*    author:  lazyhash(yashkundu)
*    created: 12 Oct, 2024 | 12:29:20
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<vector<int>> p;


bool check(int x) {
    for(int i=0;i<n;i++) {
        bool good = false;
        for(int j=0;j<m;j++) {
            if(p[j][i]>=x) {
                good = true;
                break;
            }
        }
        if(!good) return false;
    }
    for(int i=0;i<m;i++) {
        int cnt = 0;
        for(int j=0;j<n;j++) if(p[i][j]>=x) cnt++;
        if(cnt>1) return true;
    }
    return false;
}

 
void solve() {
    cin >> m >> n;

    p.resize(m);
    
    for(int i=0;i<m;i++) {
        p[i].resize(n);
        for(int j=0;j<n;j++) cin >> p[i][j];
    }

    int L = 1, R = (int)1e9+1;
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