// https://codeforces.com/problemset/problem/1898/F

/**
*   author: lazyhash(yashkundu)
*   created: 09 Jan, 2024 | 16:23:07
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int N = 1e3+5;
bool mat[N][N];
int vis[N][N];
int pre[N][N];
int sum[N][N];
int dis[N][N];
map<int, int> dis2[N][N];

int n, m;

bool isExitCell(int x, int y) {
    return x==0 || x==n-1 || y==0 || y==m-1;
}

bool insideMatrix(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};


void bfs1(int x, int y) {
    for(int i=0;i<n;i++) fill(dis[i], dis[i]+m, 0);
    dis[x][y] = 1;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    while(!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = a+dx[i], ny = b+dy[i];
            if(!insideMatrix(nx, ny) || !mat[nx][ny] || dis[nx][ny]) continue;
            dis[nx][ny] = 1 + dis[a][b];
            q.emplace(nx, ny);
        }
    }
}


// multisource-bfs
void bfs2(int x, int y) {
    for(int i=0;i<n;i++) fill(vis[i], vis[i]+m, 0), fill(pre[i], pre[i]+m, 0), fill(sum[i], sum[i]+m, 0);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) dis2[i][j].clear();
    

    queue<pair<pair<int, int>, int>> q;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(isExitCell(i, j) && dis[i][j]) q.push({{i, j}, i+1+n*j});
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(isExitCell(i, j) && dis[i][j]) {
        // init
        vis[i][j] = 1;
        pre[i][j] = i+1+n*j;
        dis2[i][j][i+1+n*j] = 0;
        sum[i][j] = 0;
    }


    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first.first, y = p.first.second, id = p.second;
        for(int i=0;i<4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!insideMatrix(nx, ny) || !mat[nx][ny] || vis[nx][ny]==2 || (vis[nx][ny] && pre[nx][ny]==id)) continue;
            dis2[nx][ny][id] = 1+dis2[x][y][id];
            vis[nx][ny]++;
            pre[nx][ny] = id;
            sum[nx][ny] += dis2[nx][ny][id];
            q.push({{nx, ny}, id});
        }
    }

}


 
void solve() {
    cin >> n >> m;
    int x, y;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) mat[i][j] = (s[j]!='#');
        for(int j=0;j<m;j++) if(s[j]=='V') {
            x = i;
            y = j;
        }
    }

    // for(int i=0;i<n;i++) fill(vis[i], vis[i]+m, 0), fill(dis[i], dis[i]+m, 0), fill(sum[i], sum[i]+m, 0);

    bfs1(x, y);
    int cnt = 0;
    for(int i=0;i<n;i++) cnt += (dis[i][0]!=0) + (dis[i][m-1]!=0);
    for(int j=0;j<m;j++) cnt += (dis[0][j]!=0) + (dis[n-1][j]!=0);


    int totEmpty = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(mat[i][j]) totEmpty++;

    if(!cnt) {
        cout << (totEmpty-1) << "\n";
        return;
    }
    
    if(cnt==1) {
        int shortestDis = 1e9;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(isExitCell(i, j) && dis[i][j]) shortestDis = min(shortestDis, dis[i][j]);
        cout << totEmpty - shortestDis << "\n";
        return; 
    }

    // >=2 reachable exit cells
    bfs2(x, y);
    int ans = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(!mat[i][j] || vis[i][j]!=2 || dis[i][j]==0) continue;
        int totPathDis = dis[i][j] + sum[i][j];
        ans = max(ans, totEmpty-totPathDis);
    }
    
    cout << ans << "\n";


    
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/