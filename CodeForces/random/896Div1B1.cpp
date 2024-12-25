/**
*    author:  lazyhash(yashkundu)
*    created: 06 Jul, 2024 | 13:09:43
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

const int MAXN = int(2e5) + 10;
int a[MAXN];

int n;
ll tot = 0;
int el;
int del;

map<int, int> cnt;
 
void solve() {
    cin >> n;
    tot = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        tot += a[i];
    }

    if(tot%n) {
        cout << "No\n";
        return;
    }

    el = int(tot/n); 
    cnt.clear();
    int msb = -1, lsb = -1;

    for(int i=0;i<n;i++) {
        if(a[i]==el) continue;
        del = abs(a[i]-el);

        msb = 31 - __builtin_clz(del);
        lsb = __builtin_ctz(del);
        if((1<<(msb+1))-(1<<lsb)!=del) {
            cout << "No\n";
            return;
        }
        int sign = a[i]>el?-1:1;
        cnt[sign*(1<<(msb+1))]++;
        cnt[-1*sign*(1<<lsb)]++;
    }

    for(auto it: cnt) {
        if(cnt[it.first]!=cnt[-it.first]) {
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