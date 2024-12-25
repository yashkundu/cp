/**
*    author:  lazyhash(yashkundu)
*    created: 19 Jul, 2024 | 21:50:25
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

const int MAXN = int(2e5)+10;

int n, m, x;
int a[MAXN], b[MAXN];

map<int, int> given, cnt, last;
vector<int> v;
 
void solve() {
    cin >> n;
    given.clear(), cnt.clear(), last.clear();
    v.clear();


    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    cin >> m;

    for(int i=0;i<m;i++) {
        cin >> x;
        given[x]++;
    }

    for(int i=0;i<n;i++) {
        if(a[i]<b[i]) {
            cout << "NO\n";
            return;
        }
    }


    

    for(int i=0;i<n;i++) {
        while(!v.empty() && b[v.back()]<=b[i]) v.pop_back();
        if(b[i]!=a[i]) {
            if(cnt[b[i]]==0) {
                cnt[b[i]]++;
                last[b[i]] = i;
            } else {
                if(!v.empty() && v.back()>last[b[i]]) cnt[b[i]]++;
                last[b[i]] = i;
            }
        }
        v.push_back(i);
    }


    for(auto [x, c]: cnt) {
        if(given[x]<c) {
            cout << "NO\n";
            return;
        }
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