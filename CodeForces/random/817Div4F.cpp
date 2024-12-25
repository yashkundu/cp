/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jul, 2024 | 14:19:16
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

const int MAXN = 55;

bool a[MAXN][MAXN];

int n, m;
string s;

bool good = true;

bool isinside(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m;
}

bool checkadj(int x, int y) {
    for(int i=-1;i<2;i++) {
        for(int j=-1;j<2;j++) {
            if(isinside(x+i, y+j) && a[x+i][y+j]) return false;
        }
    }
    return true;
}


void check(int x, int y) {
    int cnt = 0;
    pair<int, int> empty;
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            int nx = x+i, ny = y+j;
            if(!a[nx][ny]) {
                empty = {nx, ny};
            } else cnt++;
        }
    }

    if(cnt==3) {
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[x+i][y+j] = 0;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) {
            int nx = x+i, ny = y+j;
            if(make_pair(nx, ny)==empty) continue;
            if(!checkadj(nx, ny)) good = false;
        }
    }




}

 
void solve() {
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        cin >> s;
        for(int j=0;j<m;j++) a[i][j] = (s[j]=='*');
    }


    good = true;

    for(int i=0;i+2<=n;i++) {
        for(int j=0;j+2<=m;j++) {
            check(i, j);
        }
    }


    if(!good) {
        cout << "NO\n";
        return;
    }

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";


    


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