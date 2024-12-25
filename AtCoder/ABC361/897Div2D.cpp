/**
*    author:  lazyhash(yashkundu)
*    created: 07 Jul, 2024 | 16:28:29
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(1e5) + 10;

int b[MAXN];
int col[MAXN], tme[MAXN];
int timer = 0;

int n, k;
int cycle;

void func(int ind) {
    col[ind] = 1;
    tme[ind] = timer++;
    int nxt = b[ind];
    if(!col[nxt]) func(nxt);
    else if(col[nxt]==1) {
        cycle = tme[ind] - tme[nxt] + 1;
    }
    col[ind] = 2;
}
 
void solve() {
    cin >> n >> k;
    fill(col+1, col+n+1, 0);

    for(int i=1;i<=n;i++) cin >> b[i];

    if(k==1) {
        for(int i=1;i<=n;i++) {
            if(b[i]!=i) {
                cout << "No\n";
                return;
            } 
        }
        cout << "Yes\n";
        return;
    }

    timer = 0;
    for(int i=1;i<=n;i++) {
        if(col[i]) continue;
        cycle = 0;
        func(i);
        if(cycle && cycle!=k) {
            cout << "No\n";
            return;
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