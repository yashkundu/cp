/**
*    author:  lazyhash(yashkundu)
*    created: 17 Sep, 2024 | 20:44:17
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


const int inf = (int)1e9+10;

int n, m;
vector<string> s;
string ts;


char c[] = {'n', 'a', 'r', 'e', 'k'};

map<char, bool> goodchar = {
    {'n', 1}, {'a', 1}, {'r', 1}, {'e', 1}, {'k', 1}
};

vector<vector<int>> dp;

void maximize(int &x, int y) {
    x = max(x, y);
}

 
void solve() {
    cin >> n >> m;
    s.resize(n);

    for(int i=0;i<n;i++) {
        cin >> ts;
        s[i] = "";
        for(int j=0;j<m;j++) if(goodchar[ts[j]]) s[i] += ts[j]; 
    }


    dp.resize(n+1);
    for(int i=0;i<=n;i++) dp[i].resize(5);

    for(int i=0;i<=n;i++) for(int j=0;j<5;j++) dp[i][j] = -inf;
    dp[0][0] = 0;



    for(int i=0;i<n;i++) {
        for(int j=0;j<5;j++) {
            if(dp[i][j]==-inf) continue;
            maximize(dp[i+1][j], dp[i][j]);
            int score = dp[i][j];
            int ind = j;
            for(int k=0;k<s[i].size();k++) {
                if(s[i][k]==c[ind]) {
                    ind++;
                    if(ind==5) {
                        score += 5;
                        ind = 0;
                    } 
                    maximize(dp[i+1][ind], score - (s[i].size()-k-1));
                } else score--;
            }
            maximize(dp[i+1][ind], score);
        }
    }

    // debug(dp[4][0]);

    cout << dp[n][0] << "\n";

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