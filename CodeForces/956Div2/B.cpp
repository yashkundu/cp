/**
*    author:  lazyhash(yashkundu)
*    created: 07 Jul, 2024 | 20:16:44
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 505;

int a[MAXN][MAXN], b[MAXN][MAXN];

int n, m;
string s;
int del;

 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> s;
        for(int j=0;j<m;j++) a[i][j] = (s[j]-'0');
    }

    for(int i=0;i<n;i++) {
        cin >> s;
        for(int j=0;j<m;j++) b[i][j] = (s[j]-'0');
    }

    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++) {
            del = (b[i][j] - a[i][j] + 3)%3;
            if(!del) continue;
            a[i][j] = (a[i][j]+del)%3;
            a[i+1][j+1] = (a[i+1][j+1]+del)%3;
            del = 3 - del;
            a[i+1][j] = (a[i+1][j]+del)%3;
            a[i][j+1] = (a[i][j+1]+del)%3;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j]!=b[i][j]) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";




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