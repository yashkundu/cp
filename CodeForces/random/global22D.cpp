/**
*    author:  lazyhash(yashkundu)
*    created: 25 Jul, 2024 | 13:51:12
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> b;

map<int, vector<int>> mp;
set<int> st[2];

vector<int> ans;

int first, nxt;
 
void solve() {
    cin >> n;
    b.resize(n+1);
    mp.clear();
    st[0].clear(), st[1].clear();
    ans.clear();

    first = -1;

    for(int i=1;i<=n;i++) {
        cin >> b[i];
        if(!mp.count(b[i])) mp[b[i]] = vector<int>();
        mp[b[i]].push_back(i);
        if(b[i]==0 || b[i]==n+1) first = b[i];
    }

    int x = first==n+1?0:1;


    while(first!=-1) {
        nxt = -1;
        for(auto ind: mp[first]) {
            st[x].insert(ind);
            if(mp.count(ind)) nxt = ind;
        }
        x ^= 1;
        for(auto ind: mp[first]) if(ind!=nxt) ans.push_back(ind);
        if(nxt!=-1) ans.push_back(nxt);
        first = nxt;
    } 



    cout << (st[0].empty()?0:*st[0].rbegin()) << "\n";
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";

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