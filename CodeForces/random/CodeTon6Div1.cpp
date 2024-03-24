/**
*   author: lazyhash(yashkundu)
*   created: 02 Feb, 2024 | 08:25:04
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

const int N = 5000+100;
int lMex[N][N];
int a[N];
bool present[N];

// dp[i][j] -> is it possible to make xor of mexes equal to j in prefix i.
bool dp[N][N];
 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];


    for(int i=0;i<n;i++) for(int j=0;j<=n+1;j++) lMex[i][j] = n;
    for(int i=0;i<=n;i++) for(int j=0;j<=n+1;j++) dp[i][j] = 0;

//  10
//  1 2 0 7 1 2 0 2 4 3


    for(int i=0;i<n;i++) {
        fill(present, present+n+1, 0);
        int curMex = 0;
        for(int j=i;j<n;j++) {
            present[a[j]] = 1;
            while(curMex<=n && present[curMex]) curMex++;
            if(lMex[i][curMex]==n)
                lMex[i][curMex] = j;
        }
    }

    for(int j=0;j<=n+1;j++) {
        for(int i=n-2;i>=0;i--) {
            lMex[i][j] = min(lMex[i][j], lMex[i+1][j]);
        }
    }



    dp[0][0] = 1;
    // dp[i][j] -> it is possible to make xor mexes equal to j, in prefix of i where last element is in the last subarray
    fill(present, present+n+2, 0);


    for(int i=0;i<n;i++) {
        for(int j=0;j<=n+1;j++) {
            if(!dp[i][j]) continue;  
            // if it's already done before, ignore it
            if(present[j]) continue;
            // iterate over all possible values of mex of the next subsegment
            present[j] = 1;
            for(int x=1;x<=n+1;x++) {
                if(lMex[i][x]==n) continue;
                dp[lMex[i][x]+1][j^x] = 1; 
            }
        }
    }


    int ans = 0;
    for(int j=1;j<=n+1;j++) {
        for(int i=1;i<=n;i++) {
            if(dp[i][j]) {
                ans = j;
                break;
            }
        }
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