/**
*   author: lazyhash(yashkundu)
*   created: 29 Apr, 2024 | 08:24:54
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int N = 3e5+10;
int activeCnt[N] = {0};

vector<int> g[N];
vector<int> order;

int dp[N]={0}, nxt[N]={0};
bool ans[N] = {0};



void dfs(int v) {
    for(int u: g[v]) {
        dfs(u);
    }
    order.push_back(v);
}


 

int n, m;

void solve() {
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> events;

    for(int i=0;i<m;i++) {
        int row, l, r;
        cin >> row >> l >> r;
        row--;
        events.push_back({l, {1, row}});
        events.push_back({r+1, {0, row}});
    }

    set<int> st;
    sort(events.begin(), events.end());


    for(auto p: events) {
        int ind = p.first, type = p.second.first, row = p.second.second;
        if(type==0) {
            activeCnt[row]--;
            if(activeCnt[row]==0) st.erase(row);
        } else {
            activeCnt[row]++;
            if(activeCnt[row]!=1) continue;
            // enter into the set
            st.insert(row);
            auto it = st.lower_bound(row);
            if(it!=st.begin()) {
                it--;
                g[*it].push_back(row);
            }
            auto it2 = st.upper_bound(row);
            if(it2!=st.end()) g[row].push_back(*it2);
        }
    }

    // we get a DAG
    dfs(0);


    for(int v: order) {
        dp[v] = 1;
        nxt[v] = v;
        int mxLen = 1, mxV = -1;
        for(int u: g[v]) {
            if(dp[u]+1>mxLen) {
                mxLen = dp[u] + 1;
                mxV = u;
            }
        }
        if(mxLen>1) {
            dp[v] = mxLen;
            nxt[v] = mxV;
        }
    }


    int mxLen = 1;
    int start = 0;
    for(int i=0;i<n;i++) {
        if(dp[i]>mxLen) {
            mxLen = dp[i];
            start = i;
        }
    }

    ans[start] = 1;
    while(nxt[start]!=start) {
        start = nxt[start];
        ans[start] = 1;
    }

    int cnt = 0;
    for(int i=0;i<n;i++) if(!ans[i]) cnt++;

    cout << cnt << "\n";
    for(int i=0;i<n;i++) if(!ans[i]) cout << (i+1) << " ";
    cout << "\n";









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