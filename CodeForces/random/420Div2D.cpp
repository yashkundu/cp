/**
*    author:  lazyhash(yashkundu)
*    created: 12 Jun, 2024 | 09:18:14
**/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

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
 

const int inf = 1e9+10;
const int N = 1e4+10;

vector<pair<int, int>> lit;
map<pair<int, int>, int> mp;

vector<pair<int, int>> g[3*N];
int dis[3*N];

int n, m, k;
int r, c;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

set<pair<int, int>> st;


void connect(int a, int b, int w) {
    g[a].push_back({b, w});
    g[b].push_back({a, w});
}

 
void solve() {
    cin >> n >> m >> k;
    for(int i=0;i<k;i++) {
        cin >> r >> c;
        lit.push_back({r, c});
    }

    sort(lit.begin(), lit.end());
    for(int i=0;i<lit.size();i++) {
        mp[lit[i]] = n + m + i + 1;
    }



    for(int i=0;i<lit.size();i++) {
        int curInd = (n+m+i+1);
        auto [x, y] = lit[i];
        connect(curInd, x, 1);
        if(x+1<=n) connect(curInd, x+1, 1);
        if(x-1>0) connect(curInd, x-1, 1);
        connect(curInd, n+y, 1);
        if(y+1<=m) connect(curInd, n+y+1, 1);
        if(y-1>0) connect(curInd, n+y-1, 1);
        for(int k=0;k<4;k++) {
            int nX = x+ dx[k];
            int nY = y + dy[k];
            if(mp[{nX, nY}]) g[curInd].push_back({mp[{nX, nY}], 0});
        }
    }

    for(int i=0;i<3*N;i++) dis[i] = inf;

    st.insert({0, n+m+1});
    dis[n+m+1] = 0;

    while(!st.empty()) {
        int v = st.begin()->second;
        st.erase(st.begin());

        for(auto [u, w]: g[v]) {
            if(dis[v]+w<dis[u]) {
                st.erase({dis[u], u});
                dis[u] = dis[v] + w;
                st.insert({dis[u], u});
            }
        }

    }


    int cost = inf;
    for(int i=0;i<lit.size();i++) {
        int curInd = n+m+i+1;
        auto &p = lit[i];
        if((n-p.first<=1 || m-p.second <=1) && dis[curInd]!=inf) {
            cost = min(cost, dis[curInd] + (p==make_pair(n, m)?0:2));
        }
    }



    if(cost==inf) {
        cout << "-1\n";
        return;
    }

    cost /= 2;
    cout << cost << "\n";



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