/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jul, 2024 | 11:00:52
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
int sx, sy, dx, dy;

string s;


ll col;

set<pair<int, int>> st[4];
map<pair<int, int>, int> mp;


pair<int, int> getDir(string s) {
    if(s=="DR") return {1, 1};
    if(s=="DL") return {1, -1};
    if(s=="UR") return {-1, 1};
    else return {-1, -1};
}


void move(int &x, int &y, pair<int, int> &dir) {
    int nx = x + dir.first, ny = y + dir.second;
    if(nx<1 || nx>n || ny<1 || ny>m) col++;
    if(nx<1 || nx>n) dir.first *= -1;
    if(ny<1 || ny>m) dir.second *= -1;
    x = x + dir.first;
    y = y + dir.second;
}

 
void solve() {
    cin >> n >> m;
    cin >> sx >> sy >> dx >> dy;

    cin >> s;

    mp[{1, 1}] = 0;
    mp[{1, -1}] = 1;
    mp[{-1, 1}] = 2;
    mp[{-1, -1}] = 3;

    for(int i=0;i<4;i++) st[i].clear();


    pair<int, int> dir = getDir(s);

    col = 0;
    int x = sx, y = sy;
    while(true) {
        if(x==dx && y==dy) {
            cout << col << "\n";
            return;
        }
        if(st[mp[dir]].count({x, y})) {
            cout << "-1\n";
            return;
        }
        st[mp[dir]].insert({x, y});
        move(x, y, dir);
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