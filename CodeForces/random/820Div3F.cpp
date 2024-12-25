/**
*    author:  lazyhash(yashkundu)
*    created: 26 Jul, 2024 | 18:50:29
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5)+10;

int n, w , m;
string s;

int psum[MAXN];
vector<int> pos[9];

pair<int, int> ans[9][9];



pair<int, int> calc(int q, int r) {
    for(int i=1;i+w-1<=n;i++) {
        int x = (psum[i+w-1]-psum[i-1])%9;
        int req = (r - (q*x)%9 + 9)%9;
        if(pos[req].size()) {
            if(pos[req][0]!=i) return {i, pos[req][0]};
            if(pos[req].size()>1) return {i, pos[req][1]};
        }
    }
    return {-1, -1};
}

int l, r, k;
 
void solve() {
    cin >> s;
    cin >> w >> m;
    n = s.size();

    psum[0] = 0;
    for(int i=0;i<n;i++) {
        psum[i+1] = psum[i] + (s[i]-'0');
    }

    for(int i=0;i<9;i++) pos[i].clear();


    for(int i=1;i+w-1<=n;i++) {
        pos[(psum[i+w-1]-psum[i-1])%9].push_back(i);
    }

    for(int i=0;i<9;i++) for(int j=0;j<9;j++) ans[i][j] = calc(i, j);


    while(m--) {
        cin >> l >> r >> k;
        int x = (psum[r] - psum[l-1])%9;
        cout << ans[x][k].first << " " << ans[x][k].second << "\n";
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