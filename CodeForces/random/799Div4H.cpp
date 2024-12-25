/**
*    author:  lazyhash(yashkundu)
*    created: 11 Aug, 2024 | 23:29:11
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

int x[MAXN];
int n;

map<int, vector<int>> mp;
int a, l, r;
int ans;
 
void solve() {
    cin >> n;
    mp.clear();

    for(int i=1;i<=n;i++) {
        cin >> x[i];
        if(!mp.count(x[i])) mp[x[i]] = vector<int>();
        mp[x[i]].push_back(i);
    }

    ans = 1;
    a = x[1];
    l = r = 1;


    for(auto [_, v]: mp) {
        int cur = 1;
        int last = 0;
        for(int i=1;i<v.size();i++) {
            int newCur = 1 - (v[i]-v[i-1]-1) + cur;
            if(newCur>1) {
                cur = newCur;
            } else {
                cur = 1 ;
                last = i;
            }
            if(cur>ans) {
                ans = cur;
                a = x[v[i]];
                l = v[last];
                r = v[i];
            }
        }
    }

    cout << a << " " << l << " " << r << '\n';

    


    
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