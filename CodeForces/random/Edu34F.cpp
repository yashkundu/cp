/**
*   author: lazyhash(yashkundu)
*   created: 27 May, 2024 | 09:11:05
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1002;

const int inf = 1e9+10;

int dp[MAXN][256][2];
bool mat[4][MAXN];

int a[5];

int n;
char ch;
int f = 1;
int cur = 0;
int newCur = 0;
 
void solve() {
    cin >> n;
    for(int i=1;i<=4;i++) cin >> a[i];
    for(int i=0;i<4;i++) {
        for(int j=0;j<n;j++) {
            cin >> ch;
            mat[i][j] = (ch=='*');
        }
    }
    for(int i=0;i<=n;i++) for(int j=0;j<256;j++) for(int k=0;k<2;k++) dp[i][j][k] = inf;
    dp[0][0][0] = 0;


    for(int i=0;i<n;i++) {
        for(int j=0;j<256;j++) {
            for(int k=0;k<2;k++) {
                if(dp[i][j][k]==inf) continue;
                // i | j
                for(int sz=1;sz<=min(4, n-i);sz++) {
                    for(int start=0; start<=min(3, 4-sz); start++) {
                        cur = j;
                        newCur = 0;
                        f = 1;
                        for(int ptr=0;ptr<4;ptr++) {
                            int del = cur%4;
                            if(ptr>=start && ptr<start+k) del = max(del, k);
                            newCur += f*del;
                            cur /= 4;
                            f *= 4;
                        }
                        dp[i][newCur] = min(dp[i][newCur], dp[i][j]+a[k]);
                    }
                }
            }
        }
        // shift to next index
        for(int j=0;j<256;j++) {
            cur = j;
            newCur = 0;
            f = 1;
            bool good = true;
            for(int ptr=0;ptr<4;ptr++) {
                int del = cur%4;
                if(mat[j][i] && !del) good = false;
                if(del) del--;
                newCur += del*f;
                cur /= 4;
                f *= 4;
            }
            if(!good) continue;
            dp[i+1][newCur] = min(dp[i+1][newCur], dp[i][j]);
        }
    }

    cout << dp[n][0] << "\n";

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