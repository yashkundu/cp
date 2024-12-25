/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jun, 2024 | 15:37:43
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
 
const int MAXN = 1e5+500;
const int SQR = 317;

ll suf1[MAXN][SQR+1] = {0};
ll suf2[MAXN][SQR+1] = {0};

int n, q;
ll a[MAXN];

int s, d, k;

ll sum = 0;


void solve() {
    cin >> n >> q;
    
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=n;i>0;i--) {
        for(int j=1;j<=SQR;j++) {
            suf1[i][j] = a[i] + suf1[i+j][j];
            suf2[i][j] = suf1[i][j] + suf2[i+j][j];
        }
    }

    while(q--) {
        cin >> s >> d >> k;
        if(k<=SQR) {
            sum = 0;
            for(int i=s,cnt=0;cnt<k;i+=d,cnt++) {
                sum += 1LL*a[i]*(cnt+1);
            }
            cout << sum << " ";
            continue;
        }

        ll sum = suf2[s][d] - suf2[s+d*k][d] - suf1[s+d*k][d]*k;
        cout << sum << " ";
    }
    cout << "\n";

    for(int i=1;i<=n;i++) for(int j=1;j<=SQR;j++) suf1[i][j] = suf2[i][j] = 0;


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