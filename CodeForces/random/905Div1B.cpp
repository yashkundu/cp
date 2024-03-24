// 5 2

// 4
// 1 2
// 2 3
// 3 4
// 4 5

// 2
// 2 3
// 3 5

// 6
// 2 1 2 1 2 1


// 1 - 2 - 3 - 4 - 5
// 1  2 - 3 - 5  4

// min time travels to reach from 1 -> n
// sig(mi) -> 2e5
// t[i] - [2, 3, 5, 6, 10]

// 1 -> n, 
//  choose a monotonically increasing sequence
// 1 -> 2 (3)
// dp[i] -> the min time travel needed to reach 1 -> i
// i -> all edges
// easyto do


/**
*   author: lazyhash(yashkundu)
*   created: 30 Jan, 2024 | 17:57:31
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <set>
#include <algorithm>
 
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


const int N = 2e5+10;
vector<pair<int, int>> g[N];
// records[i] -> records which has ith edge
vector<int> records[N];

map<pair<int, int>, int> mp; 
// dp[i] -> min time movement required to reach from 1 -> n
int dp[N];

vector<int> pos[N];


void solve() {
    int n, t;
    cin >> n >> t;


    fill(dp, dp+n, -1);

    int cntr = 1;
    for(int i=0;i<t;i++) {
        int m;
        cin >> m;
        for(int j=0;j<m;j++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            int curCountr = -1;
            auto p = make_pair(min(x, y), max(x, y));
            if(mp[p]) {
                curCountr = mp[p];
            } else {
                mp[p] = cntr;
                curCountr = cntr++;
            }
            g[x].emplace_back(y, curCountr);
            g[y].emplace_back(x, curCountr);
            records[curCountr].push_back(i+1);
        }

    }

    int k;
    cin >> k;
    for(int i=0;i<k;i++) {
        int x;
        cin >> x;
        pos[x].push_back(i+1);
    }




    set<pair<int, int>> st;
    st.emplace(0, 0);

    while(!st.empty()) {
        auto it = st.begin();
        int a = it->first;
        int v = it->second;
        st.erase(it);
        if(dp[v]!=-1) continue;
        dp[v] = a;
        for(auto p: g[v]) {
            int recordInd = p.second;
            int u = p.first;
            if(dp[u]!=-1) continue;
            // do that here
            int minInd = 1e9;
            for(int x: records[recordInd]) {
                // pos[x] -> [1, 4, 7, 13]
                auto it2 = upper_bound(pos[x].begin(), pos[x].end(), dp[v]);
                if(it2==pos[x].end()) continue;
                minInd = min(minInd, *it2);
            }
            if(minInd!=1e9) st.emplace(minInd, u);
        }
    }

    cout << dp[n-1] << "\n";

    

    
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




