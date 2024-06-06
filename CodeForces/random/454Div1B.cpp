/**
*   author: lazyhash(yashkundu)
*   created: 26 May, 2024 | 21:40:46
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

int n, m;
vector<vector<int>> mat;
vector<int> tempRow, tempCol;
 
void solve() {
    cin >> n >> m;
    mat.resize(n);
    for(int i=0;i<n;i++) mat[i].resize(m);
    tempRow.resize(m); tempCol.resize(n);

    if(n==1 && m==1) {
        cout << "YES\n";
        cout << 1 << "\n";
        return;
    }
    if(n==1 && m==4) {
        cout << "YES\n";
        cout << "2 4 1 3\n";
        return;
    }
    if(n==4 && m==1) {
        cout << "YES\n";
        cout << "2\n4\n1\n3\n";
        return;
    }
    if(n==1 && m>4) {
        cout << "YES\n";
        for(int i=1;i<=m;i+=2) cout << i << " ";
        for(int i=2;i<=m;i+=2) cout << i << " ";
        cout << "\n";
        return;
    }
    if(m==1 && n>4) {
        cout << "YES\n";
        for(int i=1;i<=n;i+=2) cout << i << "\n";
        for(int i=2;i<=n;i+=2) cout << i << "\n";
        return;
    }
    if(n*m<=6) {
        cout << "NO\n";
        return;
    }
    if(n==3 && m==3) {
        cout << "YES\n";
        cout << "6 1 8\n7 5 3\n2 9 4\n";
        return;
    }
    bool isRow = (m>=4);

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        mat[i][j] = i*m + (j+1);
    }

    if(isRow) {
        for(int i=1;i<n;i+=2) {
            for(int j=0;j<m;j++) tempRow[j] = mat[i][(j+2)%m];
            for(int j=0;j<m;j++) mat[i][j] = tempRow[j];
        }
        for(int j=1;j<m;j+=2) {
            for(int i=0;i<n;i++) tempCol[i] = mat[(i+1)%n][j];
            for(int i=0;i<n;i++) mat[i][j] = tempCol[i];
        }
    } else {
        for(int j=1;j<m;j+=2) {
            for(int i=0;i<n;i++) tempCol[i] = mat[(i+2)%n][j];
            for(int i=0;i<n;i++) mat[i][j] = tempCol[i];
        }
        for(int i=1;i<n;i+=2) {
            for(int j=0;j<m;j++) tempRow[j] = mat[i][(j+1)%m];
            for(int j=0;j<m;j++) mat[i][j] = tempRow[j];
        }
    }

    cout << "YES\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << mat[i][j] << " ";
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