/**
*    author:  lazyhash(yashkundu)
*    created: 02 Oct, 2024 | 14:32:08
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1005;

int a[MAXN][MAXN];

vector<pair<pair<int, int>, int>> ops;

int n, m;




bool isgood(int x, int y) {
    if(x<0 || x>n-2 || y<0 || y>m-2) return false;
    int col = 0;
    for(int i=x;i<x+2;i++) {
        for(int j=y;j<y+2;j++) {
            if(!a[i][j]) continue;
            if(!col) col = a[i][j];
            else if(col!=a[i][j]) return false;
        }
    }
    if(!col) return false;
    for(int i=x;i<x+2;i++) for(int j=y;j<y+2;j++) a[i][j] = 0;
    ops.push_back({{x, y}, col});
    return true;
}

 
void solve() {
    cin >> n >> m;
    ops.clear();


    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];


    vector<pair<int, int>> v;

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(isgood(i, j)) v.push_back({i, j});




    while(!v.empty()) {
        auto [x, y] = v.back();
        v.pop_back();
        for(int i=0;i<3;i++) if(isgood(x-1, y-1+i)) v.push_back({x-1, y-1+i});
        for(int i=0;i<3;i++) if(isgood(x+1, y-1+i)) v.push_back({x+1, y-1+i});
        if(isgood(x, y-1)) v.push_back({x, y-1});
        if(isgood(x, y+1)) v.push_back({x, y+1});
    }

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]) {
        cout << "-1\n";
        return;
    }


    cout << ops.size() << "\n";

    for(int i=(int)ops.size()-1;i>=0;i--) {
        cout << ops[i].first.first+1 << " " << ops[i].first.second+1 << " " << ops[i].second << "\n";
    }







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