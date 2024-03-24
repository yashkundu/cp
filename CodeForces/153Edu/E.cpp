/**
*   author: lazyhash(yashkundu)
*   created: 29 Aug, 2023 | 22:03:19
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <deque>

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

const int N = 5e4 + 1000;
const int inf = 1e9;

int dis[26][26][N], disT[26][26][N];
string s;
int n;
vector<pair<int, int>> g[N], gT[N];
int mping[26][26];


void precalc(int (*dis)[26][N], vector<pair<int, int>> *g) {
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            int v = mping[i][j];
            // using 0-1 bfs to find shortest distance of all the vertices from the source v
            deque<int> q;
            for(int k=0;k<N;k++) dis[i][j][k] = -1;
            dis[i][j][v] = 0;
            q.push_back(v);
            while(!q.empty()) {
                int u = q.front();
                q.pop_front();
                // closes tree level to the root
                for(auto [x, w]: g[u]) {
                    if(dis[i][j][x]!=-1) continue;
                    dis[i][j][x] = dis[i][j][u] + w;
                    if(w) q.push_back(x);
                    else q.push_front(x);
                }
            }
        }
    }
}

 
void solve() {
    cin >> s;
    int n = s.size();
    int dummyCnt = n;
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            mping[i][j] = dummyCnt++;
        }
    }
    for(int i=0;i<n-1;i++) g[i].emplace_back(i+1, 1), g[i+1].emplace_back(i, 1), gT[i].emplace_back(i+1, 1), gT[i+1].emplace_back(i, 1);
    for(int i=0;i<n-1;i++) {
        g[i].emplace_back(mping[s[i]-'a'][s[i+1]-'a'], 1);
        gT[mping[s[i]-'a'][s[i+1]-'a']].emplace_back(i, 1);
        g[mping[s[i]-'a'][s[i+1]-'a']].emplace_back(i, 0);
        gT[i].emplace_back(mping[s[i]-'a'][s[i+1]-'a'], 0);
    }
    precalc(dis, g);
    precalc(disT, gT);
    int m;
    cin >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int ans = abs(a-b);
        for(int i=0;i<26;i++) {
            for(int j=0;j<26;j++) {
                if(disT[i][j][a]!=-1 && dis[i][j][b]!=-1) ans = min(ans, disT[i][j][a]+dis[i][j][b]);
            }
        }
        cout << ans << "\n";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/