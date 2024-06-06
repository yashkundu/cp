/**
*   author: lazyhash(yashkundu)
*   created: 08 May, 2024 | 12:34:51
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
 
const int N = 1e6+10;

int n, m;



vector<vector<bool>> a;
vector<vector<int>> pref;
vector<vector<int>> cnt;

vector<pair<int, int>> ans;



bool calc(int time, bool calcAns) {
    int sz = 2*time + 1;
    if(calcAns)
        ans.clear();

    auto calcNumOfX = [&](int i, int j, int k) {
        return pref[i+k-1][j+k-1] - pref[i-1][j+k-1] - pref[i+k-1][j-1] + pref[i-1][j-1];
    };

    
    for(int i=0;i<n+2;i++) for(int j=0;j<m+2;j++) cnt[i][j] = 0;

    for(int i=1;i+sz-1<=n;i++) {
        for(int j=1;j+sz-1<=m;j++) {
            if(calcNumOfX(i, j, sz)==sz*sz) {
                // this is good
                // debug("good", i, j);
                if(calcAns)
                    ans.push_back({i+time, j+time});
                cnt[i][j]++;
                cnt[i][j+sz]--;
                cnt[i+sz][j]--;
                cnt[i+sz][j+sz]++;
            }
        }
    }


    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cnt[i][j] = cnt[i][j] + cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
        if(a[i][j] && !cnt[i][j]) return false;
    }
    return true;
}



void solve() {
    cin >> n >> m;

    a.resize(n+2);
    for(int i=0;i<n+2;i++) a[i].resize(m+2);

    pref.resize(n+2);
    for(int i=0;i<n+2;i++) pref[i].resize(m+2);

    cnt.resize(n+2);
    for(int i=0;i<n+2;i++) cnt[i].resize(m+2);

    for(int i=0;i<n+2;i++) for(int j=0;j<m+2;j++) pref[i][j] = 0;

    for(int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for(int j=1;j<=m;j++) {
            a[i][j] = (s[j-1]=='X');
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            if(a[i][j]) pref[i][j]++;
        }
    }


    int l = 0, r = 500;


    while(l<r) {
        int mid = (l+r+1)/2;
        if(calc(mid, false)) l = mid;
        else r = mid - 1;
    }

    calc(l, true);

    cout << l << "\n";
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j] = 0;
    for(auto p: ans) a[p.first][p.second] = 1;


    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cout << (a[i][j]?'X':'.');
        }
        cout << "\n";
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