/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jun, 2024 | 15:38:49
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

void output(int x, int y) {
    cout << "! " << x << " " << y << endl;
    return;
}


int n, m;

vector<pair<int, int>> possible;


bool check(int x, int y) {
    if(x%2!=0 || y%2!=0) return false;
    x /= 2;
    y /= 2;
    return x>=1 && x<=n && y>=1 && y<=m;
}

 
void solve() {
    cin >> n >> m;
    possible.clear();

    int r1 = query(1, 1);
    int r2 = query(1, m);
    int r3 = query(n, 1);

    // 1-2

    if(check(-m+r1+r2+3, m+r1-r2+1)) {
        possible.push_back({(-m+r1+r2+3)/2, (m+r1-r2+1)/2});
    }

    if(check(n+r1-r3+1, -n+r1+r3+3)) {
        possible.push_back({(n+r1-r3+1)/2, (-n+r1+r3+3)/2});
    }

    int x = query(possible[0].first, possible[0].second);
    if(!x) {
        output(possible[0].first, possible[0].second);
        return;
    }

    assert(possible.size()>1);
    output(possible[1].first, possible[1].second);




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