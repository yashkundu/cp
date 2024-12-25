/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jun, 2024 | 21:41:22
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5+10;
int p[MAXN];
vector<pair<int, int>> moves;


int n, x;
 
void solve() {
    cin >> n >> x;
    for(int i=1;i<=n;i++) cin >> p[i];
    moves.clear();

    int ind = -1;
    for(int i=1;i<=n;i++) if(p[i]==x) {
        ind = i;
        break;
    }

    if(ind!=1) {
        swap(p[1], p[ind]);
        moves.push_back({1, ind});
    }

    int l = 1, r = n+1;
    while(r-l>1) {
        int m = (l+r)/2;
        if(p[m]<=x) l = m;
        else r = m;
    }

    if(l!=1) moves.push_back({1, l});

    cout << moves.size() << "\n";
    for(auto [x, y]: moves) cout << x << " " << y << "\n";
    




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