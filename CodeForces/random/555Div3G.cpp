/**
*   author: lazyhash(yashkundu)
*   created: 11 May, 2024 | 10:17:18
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

const int N = 200+5;
bool a[N][N], ta[N][N];

int n, m;

vector<int> rows, cols;
vector<int> rowAns(N, 0), colAns(N, 0);


bool check() {
    bool trans = false;
    for(int i=0;i<n;i++) {
        int cnt = 0;
        for(int j=0;j<m;j++) {
            cnt += ta[i][j];
        }
        if(trans && (cnt!=0 && cnt!=m)) return false;
        if(cnt!=0 && cnt!=m) trans = true;
        if(!trans) {
            if(ta[i][0]) rows.push_back(i);
        } else {
            if((cnt==0||cnt==m) && !ta[i][0]) rows.push_back(i);
            if(cnt!=0 && cnt!=m) {
                if(ta[i][0]) {
                    rows.push_back(i);
                    for(int j=0;j<m;j++) ta[i][j] = !ta[i][j];
                    for(int j=1;j<m;j++) if(ta[i][j]<ta[i][j-1]) return false;
                }
            }
        }
    }
    return true;
}

 
void solve() {

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int x;
            cin >> x;
            a[i][j] = (x==1);
        }
    }

    cols.clear(), rows.clear();
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) ta[i][j] = a[i][j];
    // debug(ta[0][0], ta[0][1], ta[1][0], ta[1][1]);
    for(int j=0;j<m;j++) {
        if(a[0][j]) {
            cols.push_back(j);
            for(int i=0;i<n;i++) ta[i][j] = !ta[i][j];
        }
    }

    // debug(cols);
    // debug(ta[0][0], ta[0][1], ta[1][0], ta[1][1]);

    if(check()) {
        cout << "YES\n";
        // debug(rows);
        // debug(cols);
        for(int r: rows) rowAns[r] = 1;
        for(int c: cols) colAns[c] = 1;
        for(int i=0;i<n;i++) cout << rowAns[i];
        cout << "\n";
        for(int j=0;j<m;j++) cout << colAns[j];
        cout << "\n";
        return;
    }

    cols.clear(), rows.clear();
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) ta[i][j] = a[i][j];
    for(int j=0;j<m;j++) {
        if(!a[n-1][j]) {
            cols.push_back(j);
            for(int i=0;i<n;i++) ta[i][j] = !ta[i][j];
        }
    }

    if(check()) {
        cout << "YES\n";
        for(int r: rows) rowAns[r] = 1;
        for(int c: cols) colAns[c] = 1;
        for(int i=0;i<n;i++) cout << rowAns[i];
        cout << "\n";
        for(int j=0;j<m;j++) cout << colAns[j];
        cout << "\n";
        return;
    }

    cout << "NO\n";



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