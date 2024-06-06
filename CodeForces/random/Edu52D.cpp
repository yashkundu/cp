/**
*   author: lazyhash(yashkundu)
*   created: 14 May, 2024 | 09:03:42
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

// 0 - knight
// 1 - bishop
// 2 - rook

const int N = 10;
const int M = 3;

pair<int, int> dp[N*N][M];
pair<int, int> pos[N*N];

const int inf = 1e9+10;


int a[N][N];
 
int n;

vector<pair<int, int>> delta = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool isInside(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

bool isReachable(int x1, int y1, int x2, int y2, int piece) {
    switch (piece) {
        case 0:
            {
            int a = abs(x1-x2);
            int b = abs(y1-y2);
            return (a==1 && b==2) || (a==2 && b==1);
            }
        case 1:
            return (x1-y1==x2-y2) || (x1+y1==x2+y2);
        case 2:
            return (x1==x2) || (y1==y2);
    }
    return false;
}

void solve() {
    cin >> n;

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        cin >> a[i][j];
        a[i][j]--;
        pos[a[i][j]] = {i, j};
    }

    for(int i=0;i<n*n;i++) for(int j=0;j<3;j++) dp[i][j] = {inf, inf};
    for(int j=0;j<3;j++) dp[0][j] = {0, 0};


    for(int i=0;i<n*n-1;i++) {
        for(int j=0;j<3;j++) {
            // move to all the possible cells where the current piece can move
            auto curPos = pos[i];
            auto nxtPos = pos[i+1];

            // should consider three moves for horse

            for(int k=0;k<N*N;k++) {
                if(i==k) continue;
                auto middlePos = pos[k];
                if(!isReachable(curPos.first, curPos.second, middlePos.first, middlePos.second, j)) continue;
                if(nxtPos==middlePos) {
                    dp[i+1][j] = min(dp[i+1][j], {dp[i][j].first+1, dp[i][j].second});
                } else {
                    for(int nPiece=0;nPiece<3;nPiece++) {
                        if(!isReachable(middlePos.first, middlePos.second, nxtPos.first, nxtPos.second, nPiece)) continue;
                        dp[i+1][nPiece] = min(dp[i+1][nPiece], {dp[i][j].first+2+(j==nPiece?0:1), dp[i][j].second + (j==nPiece?0:1)});
                    }
                }
            }
        }

        pair<int, int> mnVal = {inf, inf};
        for(int j=0;j<3;j++) mnVal = min(mnVal, dp[i+1][j]);

        for(int j=0;j<3;j++) dp[i+1][j] = min(dp[i+1][j], {mnVal.first+1, mnVal.second+1});
    }

    debug(dp[0][0], dp[1][0], dp[2][0], dp[2][2], dp[3][2]);
    debug(dp[2][0], dp[2][1], dp[2][2]);
    debug(dp[3][0], dp[3][1], dp[3][2]);

    pair<int, int> ans = {inf, inf};

    for(int j=0;j<M;j++) ans = min(ans, dp[n*n-1][j]);

    cout << ans.first << " " << ans.second << "\n";


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