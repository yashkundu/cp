/**
*   author: lazyhash(yashkundu)
*   created: 31 Mar, 2024 | 16:41:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <functional>
 
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


const int N = 2e5 + 10;

vector<ll> cards[N][3];

ll dp[N][10];

 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<3;j++) cards[i][j].clear();

    for(int i=0;i<n;i++) {
        int k;
        cin >> k;
        for(int j=0;j<k;j++) {
            int c, d;
            cin >> c >> d;
            c--;
            cards[i][c].push_back(d);
        }
    }

    for(int i=0;i<n;i++) for(int j=0;j<3;j++) sort(cards[i][j].begin(), cards[i][j].end(), greater<int>());


    for(int i=0;i<=n;i++) for(int j=0;j<10;j++) dp[i][j] = -1;
    dp[0][0] = 0;


    for(int i=0;i<n;i++) {
        for(int j=0;j<10;j++) {
            if(dp[i][j]==-1) continue;

            // choose 0 card
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

            // choose 1 card
            ll maxDCard = 0;
            for(int p=0;p<3;p++) {
                if(cards[i][p].size()) maxDCard = max(maxDCard, cards[i][p][0]);
            }
            if(j+1>=10) maxDCard *= 2;
            dp[i+1][(j+1)%10] = max(dp[i+1][(j+1)%10], maxDCard + dp[i][j]);

            // choose 2 cards
            ll card1 = (cards[i][0].size()?cards[i][0][0]:0), card2 = (cards[i][0].size()>1?cards[i][0][1]:0);
            if(cards[i][1].size() && cards[i][1][0]>card2) card2 = cards[i][1][0];
            if(card1!=0 && card2!=0) {
                dp[i+1][(j+2)%10] = max(dp[i+1][(j+2)%10], ((j+2>=10)?(card1+card2+max(card1, card2)):(card1+card2)) + dp[i][j]);
            }

            // choose 3 cards (all ones)
            if(cards[i][0].size()<3) continue;
            ll delta = cards[i][0][0] + cards[i][0][1] + cards[i][0][2];
            if(j+3>=10) delta += max({cards[i][0][0], cards[i][0][1], cards[i][0][2]});
            dp[i+1][(j+3)%10] = max(dp[i+1][(j+3)%10], delta + dp[i][j]);
        }
    }



    ll ans = 0;
    for(int j=0;j<10;j++) ans = max(ans, dp[n][j]);
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