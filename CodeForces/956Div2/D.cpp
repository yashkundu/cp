/**
*    author:  lazyhash(yashkundu)
*    created: 07 Jul, 2024 | 21:29:44
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(1e5)+10;

int a[MAXN], b[MAXN];
bool vis[MAXN];

map<int, int> mp;
int n;
int cnt;
 
void solve() {
    cin >> n;

    mp.clear();

    for(int i=1;i<=n;i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    for(int i=1;i<=n;i++) {
        cin >> b[i];
    }

    for(int i=1;i<=n;i++) {
        if(!mp[b[i]]) {
            cout << "NO\n";
            return;
        }
        b[i] = mp[b[i]];
    }

    cnt = 0;
    int del =0;
    int cur = -1;

    fill(vis+1, vis+n+1, 0);

    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        del = 1;
        cur = i;
        vis[i] = 1;
        while(!vis[b[cur]]) {
            del++;
            cur = b[cur];
            vis[cur] = 1;
        }
        cnt += (del-1);
    }


    if(cnt&1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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