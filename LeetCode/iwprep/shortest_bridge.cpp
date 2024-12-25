/**
*    author:  lazyhash(yashkundu)
*    created: 03 Nov, 2024 | 20:23:27
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue> 

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 105;
int a[MAXN][MAXN];
int dis[MAXN][MAXN];
bool vis[MAXN][MAXN];



int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int n;

bool is_inside(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}


void dfs(int x, int y) {
    vis[x][y] = true;
    for(int i=0;i<4;i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(is_inside(nx, ny) && a[nx][ny] && !vis[nx][ny]) dfs(nx, ny);
    }
}





 
void solve() {
    cin >> n;

    pair<int, int> start;

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        cin >> a[i][j];
        if(a[i][j]) start = {i, j};
    }

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) vis[i][j] = 0;
    dfs(start.first, start.second);

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dis[i][j] = -1;


    queue<pair<int, int>> q;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(vis[i][j]) {
        dis[i][j] = 0;
        q.push({i, j});
    }


    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if(!is_inside(x, y) || dis[nx][ny]!=-1) continue;
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx, ny});
        }
    }


    int ans = 10000;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a[i][j] && dis[i][j]) ans = min(ans, dis[i][j]);

    cout << ans-1 << "\n";





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