/**
*   author: lazyhash(yashkundu)
*   created: 25 Dec, 2023 | 13:29:39
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
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

const int N = 1e6+10;
int mexCnt[N];
bool vis[N];
 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin >> p[i];

    fill(mexCnt, mexCnt+n+1, 0);
    fill(vis, vis+n+1, 0);
     
    int curMex = 0;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        vis[p[i]] = 1;
        while(curMex<n && vis[curMex]) curMex++;
        ans += curMex;
        mexCnt[curMex]++;
    }


    ll res = ans;

    deque<int> dq;
    for(int i=0;i<=n;i++) if(mexCnt[i]) dq.push_back(i);


    for(int i=0;i<n;i++) {
        // pushing each element from the front to the back

        // removing the first one
        int firstMex = (p[i]==0?1:0);
        ll curAns = ans;
        curAns -= firstMex;
        mexCnt[firstMex]--;
        if(!mexCnt[firstMex]) dq.pop_front();

        // dealing with middles ones
        while(!dq.empty() && dq.back()>p[i]) {
            int lastMex = dq.back();
            curAns -= 1LL*(lastMex-p[i])*mexCnt[lastMex];
            mexCnt[p[i]] += mexCnt[lastMex];
            mexCnt[lastMex] = 0;
            dq.pop_back();
        }
        dq.push_back(p[i]);

        // dealing with the last element
        dq.push_back(n);
        curAns += n;
        mexCnt[n]++;

        ans = curAns;
        res = max(res, ans);
    }

    cout << res << "\n";




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