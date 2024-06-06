/**
*   author: lazyhash(yashkundu)
*   created: 26 May, 2024 | 13:08:28
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set __gnu_pbds::tree<pair<int, int>, __gnu_pbds::null_type,less<pair<int, int>>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> 

int q;
map<string, pair<int, int>> store;
map<int, pair<string, pair<pair<int, int>, pair<int, int>>>> changes;
 
string type;
string a;
int x, d;

ordered_set ost;

void solve() {
    cin >> q;
    int day = 0;
    while(q--) {
        day++;
        cin >> type;
        if(type=="set") {
            cin >> a;
            cin >> x;
            pair<pair<int, int>, pair<int, int>> change;
            if(store.find(a)!=store.end()) {
                change.first = store[a];
                ost.erase(change.first);
            } else {
                change.first = {0, 0};
            }
            change.second = {x, day};
            store[a] = {x, day};
            ost.insert({x, day});
            changes[day] = {a, change};
        } else if(type=="remove") {
            cin >> a;
            if(store.find(a)!=store.end()) {
                changes[day] = {a, {store[a], {0, 0}}};
                ost.erase(store[a]);
                store.erase(a);
            }
        } else if(type=="query") {
            cin >> a;
            if(store.find(a)==store.end()) {
                cout << "-1" << endl;
            } else {
                int p = store[a].first;
                int ans = ost.order_of_key({p, 0});
                cout << ans << endl;
            }
        } else {
            cin >> d;
            while(!changes.empty() && changes.rbegin()->first>=day-d) {
                auto it = changes.end();
                it--;
                auto p = it->second;
                string curA = p.first;
                pair<pair<int, int>, pair<int, int>> change = p.second;
                if(change.second.first) {
                    ost.erase(change.second);
                    store.erase(curA);
                } 
                if(change.first.first) {
                    ost.insert(change.first);
                    store[curA] = change.first;
                }
                changes.erase(it);
            } 

        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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