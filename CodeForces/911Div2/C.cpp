/**
*   author: lazyhash(yashkundu)
*   created: 10 Dec, 2023 | 12:58:28
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5+10;

int tree[N][2] = {0};
string s;


void dfs(int v, int count, int &ans) {
    if(!tree[v][0] && !tree[v][1]) ans = min(ans, count);
    if(tree[v][0]) dfs(tree[v][0], count + ((s[v]!='L')?1:0), ans);
    if(tree[v][1]) dfs(tree[v][1], count + ((s[v]!='R')?1:0), ans);
}

 
void solve() {

    int n;
    cin >> n;
    cin >> s;

    for(int i=0;i<n;i++) tree[i][0] = tree[i][1] = 0;

    for(int i=0;i<n;i++) {
        cin >> tree[i][0] >> tree[i][1];
        if(tree[i][0]) tree[i][0]--;
        if(tree[i][1]) tree[i][1]--;
    }

    int ans = 1e9;
    dfs(0, 0, ans);

    cout << ans << "\n";


   
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