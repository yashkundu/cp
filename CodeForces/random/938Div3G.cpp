/**
*    author:  lazyhash(yashkundu)
*    created: 18 Jun, 2024 | 12:55:45
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


const int MAXN = 101;

int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}


bool dp[MAXN][MAXN][MAXN*100];
int a[MAXN][MAXN];

int inds[1000010];


vector<int> divs;
int n, m;

int getInd(int x) {
    return inds[x];
}

 
void solve() {
    cin >> n >> m;

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];

    
    divs.clear();
    int x = a[0][0];
    for(int i=1;i*i<=x;i++) {
        if(x%i==0) {
            divs.push_back(i);
            divs.push_back(x/i);
        }
    }
    sort(divs.begin(), divs.end());

    for(int i=0;i<divs.size();i++) inds[divs[i]] = i;


    for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(int k=0;k<divs.size();k++) dp[i][j][k] = 0;
    dp[0][0][getInd(a[0][0])] = 1;

    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<divs.size();k++) {
                if(!dp[i][j][k]) continue;
                if(i<n-1) dp[i+1][j][getInd(gcd(divs[k], a[i+1][j]))] = 1;
                if(j<m-1) dp[i][j+1][getInd(gcd(divs[k], a[i][j+1]))] = 1;
            }
        }
    }

    int ans = 0;
    for(int i=(int)divs.size()-1;i>=0;i--) if(dp[n-1][m-1][i]) {
        ans = divs[i];
        break;
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/