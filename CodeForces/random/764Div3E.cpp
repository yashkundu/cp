/**
*    author:  lazyhash(yashkundu)
*    created: 09 Oct, 2024 | 11:51:00
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
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

const int MAXN = 1005;
 
pair<pair<int, int>, int> dp[MAXN];
map<string, pair<pair<int, int>, int>> mp;


int n, m;
string s, a;
string ss;

vector<pair<pair<int, int>, int>> segs;



void solve() {
    cin >> n >> m;
    mp.clear();


    for(int i=0;i<n;i++) {
        cin >> a;
        for(int j=0;j+1<m;j++) {
            ss = a.substr(j, 2);
            if(!mp.count(ss)) mp[ss] = {{j, j+1}, i};
        } 
        for(int j=0;j+2<m;j++) {
            ss = a.substr(j, 3);
            if(!mp.count(ss)) mp[ss] = {{j, j+2}, i};
        }
    }

    cin >> s;


    for(int i=0;i<=m;i++) dp[i] = {{-1,-1}, -1};

    dp[0] = {{0, 0}, 0};


    for(int i=0;i<m;i++) {
        if(dp[i].second==-1) continue;
        if(i+1<m) {
            ss = s.substr(i, 2);
            if(mp.count(ss)) {
                dp[i+2] = mp[ss];
            }
        }
        if(i+2<m) {
            ss = s.substr(i, 3);
            if(mp.count(ss)) {
                dp[i+3] = mp[ss];
            }
        }
    }


    if(dp[m].second==-1) {
        cout << "-1\n";
        return;
    }

    segs.clear();


    int len = m;

    while(len>0) {
        // debug(len, dp[len]);
        segs.push_back(dp[len]);
        len -= dp[len].first.second - dp[len].first.first + 1;
    }

    cout << segs.size() << "\n";

    for(auto it=segs.rbegin();it!=segs.rend();it++) {
        cout << it->first.first+1 << " " << it->first.second+1 << " " << it->second+1 << "\n";
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