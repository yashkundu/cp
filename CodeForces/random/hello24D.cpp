/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jun, 2024 | 11:51:41
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5+10;
int a[MAXN], nxt[MAXN], prv[MAXN];
bool taken[MAXN];

int n;

bool isGood(int ind) {
    if(ind<1 || ind>n) return false;
    return a[prv[ind]]==a[ind]-1 || a[nxt[ind]]==a[ind]-1;
}

 
void solve() {
    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >>a[i];
        nxt[i] = i+1;
        prv[i] = i-1;
        taken[i] = 0;
    }

    a[0] = a[n+1] = -2;

    priority_queue<pair<int, int>> pq;

    for(int i=1;i<=n;i++) {
        if(isGood(i)) {
            taken[i] = 1;
            pq.push({a[i], i});
        }
    }

    while(!pq.empty()) {
        auto [_, ind] = pq.top(); pq.pop();
        nxt[prv[ind]] = nxt[ind];
        prv[nxt[ind]] = prv[ind];
        if(!taken[prv[ind]] && isGood(prv[ind])) {
            taken[prv[ind]] = 1;
            pq.push({a[prv[ind]], prv[ind]});
        }
        if(!taken[nxt[ind]] && isGood(nxt[ind])) {
            taken[nxt[ind]] = 1;
            pq.push({a[nxt[ind]], nxt[ind]});
        }
    }

    int mn = n, bad = 0;
    for(int i=1;i<=n;i++) {
        if(!taken[i]) {
            bad++;
            mn = min(mn, a[i]);
        }
    }

    if(bad==1 && mn==0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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