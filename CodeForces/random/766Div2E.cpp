/**
*   author: lazyhash(yashkundu)
*   created: 20 Apr, 2024 | 13:06:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
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

const int N = 1e5+10;
int x[N];
vector<int> heads[N];

// the minimum health loss for a particular coordinate
map<pair<int, int>, ll> dp;


struct Ladder {
    int a, b, c, d, h;
    Ladder(int a, int b, int c, int d, int h): a(a), b(b), c(c), d(d), h(h) {}
    bool operator<(const Ladder &l) const{
        return this->b < l.b;
    }
};

vector<Ladder> ladders[N];
const ll inf = 1e18;

int n, m, k;
 
void solve() {

    cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> x[i];

    for(int i=0;i<n;i++) heads[i].clear();
    for(int i=0;i<n;i++) ladders[i].clear();
    heads[0].push_back(0);

    

    for(int i=0;i<k;i++) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        a--, b--, c--, d--;
        heads[c].push_back(d);
        ladders[a].push_back(Ladder(a, b, c, d, h));
    }

    for(int i=0;i<n;i++) sort(ladders[i].begin(), ladders[i].end());
    for(int i=0;i<n;i++) sort(heads[i].begin(), heads[i].end());




    for(int i=0;i<n;i++) heads[i].resize(unique(heads[i].begin(), heads[i].end()) - heads[i].begin());

    for(int i=0;i<n;i++) for(int j=0;j<heads[i].size();j++) {
        dp[{i, heads[i][j]}] = inf;
    }

    dp[{0, 0}] = 0;

    for(int i=0;i<n;i++) {
        // tails[i] -> [. . . . .]
        
        if(ladders[i].empty() || heads[i].empty()) continue;
        int first = heads[i][0];
        int j = 0;
        ll minLoss = inf;

        // forward
        for(Ladder &l: ladders[i]) {
            while(j<heads[i].size() && heads[i][j]<=l.b) {
                if(dp[{i, heads[i][j]}]==inf) {
                    j++;
                    continue;
                }
                minLoss = min(minLoss, dp[{i, heads[i][j]}] - 1LL*(heads[i][j]-first)*x[i]);
                j++;
            }
            if(minLoss==inf) continue;
            dp[{l.c, l.d}] = min(dp[{l.c, l.d}], minLoss + 1LL*(l.b-first)*x[i] - l.h);
        }

        // backward
        j = heads[i].size()-1;

        int last = heads[i].back();
        minLoss = inf;
        for(int k=ladders[i].size()-1;k>=0;k--) {
            Ladder &l = ladders[i][k];
            while(j>=0 && heads[i][j]>=l.b) {
                if(dp[{i, heads[i][j]}]==inf) {
                    j--;
                    continue;
                }
                minLoss = min(minLoss, dp[{i, heads[i][j]}] - 1LL*(last-heads[i][j])*x[i]);
                j--;
            }
            if(minLoss==inf) continue;
            dp[{l.c, l.d}] = min(dp[{l.c, l.d}], minLoss + 1LL*(last-l.b)*x[i] - l.h);
        }
    }

    ll ans = inf;
    for(int col: heads[n-1]) {
        if(dp[{n-1, col}]==inf) continue;
        ans = min(ans, dp[{n-1, col}] + 1LL*abs(m-1-col)*x[n-1]);
    }

    if(ans==inf) {
        cout << "NO ESCAPE\n";
        return;
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