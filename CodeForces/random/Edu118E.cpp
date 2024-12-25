/**
*    author:  lazyhash(yashkundu)
*    created: 13 Oct, 2024 | 18:40:46
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
vector<vector<char>> a;
 
string s;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isinside(int x, int y) {
    if(x<0 || x>=n || y<0 || y>=m) return false;
    return true;
}


bool isgood(int x, int y) {
    int good = 0, tot = 0;
    for(int i=0;i<4;i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(!isinside(nx, ny) || a[nx][ny]=='#') continue;
        tot++;
        if(a[nx][ny]=='+') good++;
    }
    return good && good>=tot-1;
}


void dfs(int x, int y) {
    for(int i=0;i<4;i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(!isinside(nx, ny) || a[nx][ny]!='.') continue;
        if(isgood(nx, ny)) {
            a[nx][ny] = '+';
            dfs(nx, ny);
        }
    }
}


void solve() {
    cin >> n >> m;
    a.resize(n);

    pair<int, int> p;

    for(int i=0;i<n;i++) {
        a[i].resize(m);
        cin >> s;
        for(int j=0;j<m;j++) {
            a[i][j] = s[j];
            if(a[i][j]=='L') p = {i, j};
        }
    }

    a[p.first][p.second] = '+';
    dfs(p.first, p.second);
    a[p.first][p.second] = 'L';


    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << a[i][j];
        cout << "\n";
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