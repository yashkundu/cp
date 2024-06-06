/**
*   author: lazyhash(yashkundu)
*   created: 24 May, 2024 | 08:32:35
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 4e5+10;
const int MAXM = 19;

const ll inf = 1e16;

int par[MAXN][MAXM]={0};
ll maxW[MAXN][MAXM];

int nxt[MAXN][MAXM]={0};
ll sum[MAXN][MAXM];

ll w[MAXN];

int Q, t;
ll p, q;
ll last = 0;
int cnt = 1;
 
void solve() {

    w[0] = inf;
    w[1] = 0;

    for(int j=0;j<MAXM;j++) maxW[0][j] = maxW[1][j] = inf;
    for(int j=0;j<MAXM;j++) sum[0][j] = sum[1][j] = inf;

    cin >> Q;
    while(Q--) {
        cin >> t;
        if(t==1) {
            cnt++;
            cin >> p >> q;
            p = p^last;
            q = q^last;
            w[cnt] = q;
            par[cnt][0] = p;
            for(int j=1;j<MAXM;j++) par[cnt][j] = par[par[cnt][j-1]][j-1];
            maxW[cnt][0] = w[par[cnt][0]];
            for(int j=1;j<MAXM;j++) maxW[cnt][j] = max(maxW[cnt][j-1], maxW[par[cnt][j-1]][j-1]);

            // calculating nxt
            int cur = cnt;
            for(int j=MAXM-1;j>=0;j--) {
                if(maxW[cur][j]<w[cnt]) {
                    cur = par[cur][j];
                }
            }
            
            nxt[cnt][0] = par[cur][0];
            for(int j=1;j<MAXM;j++) nxt[cnt][j] = nxt[nxt[cnt][j-1]][j-1];

            sum[cnt][0] = w[nxt[cnt][0]];
            for(int j=1;j<MAXM;j++) sum[cnt][j] = min(sum[cnt][j-1] + sum[nxt[cnt][j-1]][j-1], inf);

        } else {
            cin >> p >> q;
            p = p^last;
            q = q^last;
            if(w[p]>q) {
                last = 0;
                cout << last << "\n";
                continue;
            }
            ll ans = 1;
            q -= w[p];
            int cur = p;
            for(int j=MAXM-1;j>=0;j--) {
                if(sum[cur][j]<=q) {
                    cur = nxt[cur][j];
                    ans += (1<<j);
                    q -= sum[cur][j];
                }
            }
            last = ans;
            cout << last << "\n";
        }
    }



    
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