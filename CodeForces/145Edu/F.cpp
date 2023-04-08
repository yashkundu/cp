/**
*   author: lazyhash(yashkundu)
*   created: 26 Mar, 2023 | 16:35:22
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


const int N = 2e5+10;
const int LG = 20;

vector<ll> a(2*N);
vector<bool> b(2*N);

vector<ll> preA(2*N, 0);
vector<int> rB(2*N, 0);

// length, cost
vector<vector<pair<int, ll>>> nxt(2*N, vector<pair<int, ll>>(LG, {-1, -1LL}));
 
void solve() {
    
    int n, k;
    cin >> n >> k;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        b[i] = x==1;
        b[i+n] = b[i];
    }

    for(int i=0;i<2*n;i++) preA[i+1] = preA[i] + a[i];
    for(int i=0;i<2*n;i++) rB[i] = 1e9;
    for(int i=2*n-2;i>=0;i--) {
        rB[i] = rB[i+1];
        if(b[i+1]) rB[i] = i+1;
    }



    for(int i=0;i<2*n;i++) for(int j=0;j<LG;j++) nxt[i][j] = {-1, -1LL};

    for(int i=0;i<2*n-1;i++) {
        // a[i], b[i]
        if(!b[i]) {
            nxt[i][0] = {1, 2*a[i]};
        } else if(b[i+1]){
            nxt[i][0] = {1, a[i]};
        } else {
            int ind = lower_bound(preA.begin()+1, preA.begin()+2*n, k+preA[i]) - preA.begin()-1;
            ind = min(ind, i+n-1);
            if(rB[i]<=ind) {
                nxt[i][0] = {rB[i]-i, preA[rB[i]]-preA[i]};
            } else {
                nxt[i][0] = {ind+1-i, k + 2*(preA[ind+1]-preA[i]-k)};
            }
        }
    }

    for(int i=2*n-2;i>=0;i--) {
        for(int j=1;j<LG;j++) {
            if(nxt[i][j-1].first==-1) break;
            if(nxt[i+nxt[i][j-1].first][j-1].first==-1) nxt[i][j] = {-1, -1};
            else nxt[i][j] = {nxt[i][j-1].first + nxt[i+nxt[i][j-1].first][j-1].first, nxt[i][j-1].second + nxt[i+nxt[i][j-1].first][j-1].second};
        }
    }

    for(int i=0;i<n;i++) {
        ll ans = 0;
        int cur = i;
        for(int j=19;j>=0;j--) {
            if(nxt[cur][j].first==-1 || nxt[cur][j].first>n) continue;
            ans += nxt[cur][j].second;
            cur += nxt[cur][j].first;
        }
        cout << ans << " ";
    }

    cout << "\n";



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