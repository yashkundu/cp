/**
*    author:  lazyhash(yashkundu)
*    created: 02 Jul, 2024 | 15:25:38
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 16;
bool hor[MAXN][MAXN], ver[MAXN][MAXN];

int n, m, k;

void invert(bool &b) {
    b = !b;
}
 
void solve() {
    cin >> n >> m >> k;
    int del = (n+m-2);
    if(del>k || (del%2!=k%2)) {
        cout << "NO\n";
        return;
    }



    for(int j=0;j<m-1;j++) hor[0][j] = (j&1);

    for(int i=0;i<n-1;i++) ver[i][m-1] = hor[0][m-2] ^ ((i+1)&1);
    ver[n-2][m-2] = ver[n-2][m-1];
    hor[n-2][m-2] = hor[n-1][m-2] = (ver[n-2][m-1]^1);

    if((k-del)%4) {
        invert(hor[n-2][m-2]);
        invert(hor[n-1][m-2]);
        invert(ver[n-2][m-2]);
        invert(ver[n-2][m-1]);
    }


    cout << "YES\n";

    for(int i=0;i<n;i++) {
        for(int j=0;j<m-1;j++) cout << (hor[i][j]?'R':'B') << " ";
        cout << "\n";
    }

    for(int i=0;i<n-1;i++) {
        for(int j=0;j<m;j++) cout << (ver[i][j]?'R':'B') << " ";
        cout << "\n";
    }


    

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