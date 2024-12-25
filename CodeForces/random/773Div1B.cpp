/**
*    author:  lazyhash(yashkundu)
*    created: 02 Oct, 2024 | 11:53:38
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

int n;
vector<int> a;
vector<pair<int, int>> ops;
vector<int> lens;

map<int, int> mp;
 
void solve() {
    cin >> n;
    a.resize(n);
    mp.clear();
    
    for(int i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]]++;
    }


    for(auto p: mp) {
        if(p.second&1) {
            cout << "-1\n";
            return;
        }
    }

    ops.clear();
    lens.clear();



    int cur = 0;


    while(a.size()>2) {
        vector<int> ta;
        int ind = 1;
        while(a[ind]!=a[0]) ind++;
        for(int i=1;i<ind;i++) ops.push_back({cur+ind+i, a[i]});
        for(int i=ind-1;i>0;i--) ta.push_back(a[i]);
        for(int i=ind+1;i<a.size();i++) ta.push_back(a[i]);
        lens.push_back(2*ind);
        cur += 2*ind;
        swap(a, ta);
    }

    lens.push_back(2);


    cout << ops.size() << "\n";
    for(auto p: ops) cout << p.first << " " << p.second << "\n";

    cout << lens.size() << "\n";
    for(int x: lens) cout << x << " ";
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