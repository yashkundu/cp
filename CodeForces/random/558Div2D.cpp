/**
*   author: lazyhash(yashkundu)
*   created: 01 Apr, 2024 | 05:45:27
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
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


vector<int> prefixFunction(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1;i<n;i++) {
        int j = pi[i-1];
        while(j>0 && s[j]!=s[i]) j = pi[j-1];
        if(s[j]==s[i]) j++;
        pi[i] = j;
    }
    return pi;
}

const int N = 1001;
const int M = 51;

int dp[N][M][M];

const int inf = 1e9 + 10;

 
void solve() {
    string c, s, t;
    cin >> c >> s >> t;

    vector<int> piS = prefixFunction(s);
    vector<int> piT = prefixFunction(t);


    int n = c.size();
    int n1 = s.size(), n2 = t.size();

    for(int i=0;i<=n;i++) for(int j=0;j<n1;j++) for(int k=0;k<n2;k++) dp[i][j][k] = -inf;


    dp[0][0][0] = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n1;j++) {
            for(int k=0;k<n2;k++) {
                for(char ch='a';ch<='z'; ch++) {
                    if(c[i]!='*' && c[i]!=ch) continue;
                    int del = 0;
                    int pre1 = j;
                    while(pre1>0 && s[pre1]!=ch) pre1 = piS[pre1-1];
                    if(s[pre1]==ch) pre1++;
                    if(pre1==n1) {
                        del++;
                        pre1 = piS[pre1-1];
                    }
                    int pre2 = k;
                    while(pre2>0 && t[pre2]!=ch) pre2 = piT[pre2-1];
                    if(t[pre2]==ch) pre2++;
                    if(pre2==n2) {
                        del--;
                        pre2 = piT[pre2-1];
                    }
                    dp[i+1][pre1][pre2] = max(dp[i+1][pre1][pre2], dp[i][j][k] + del);
                }
            }
        }
    }

    int ans = -inf;
    for(int j=0;j<n1;j++) for(int k=0;k<n2;k++) ans = max(ans, dp[n][j][k]);

    cout << ans << "\n";

    

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