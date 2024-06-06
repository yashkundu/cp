/**
*   author: lazyhash(yashkundu)
*   created: 15 Apr, 2024 | 10:47:20
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int inf = 1e9+10;

int tree[4*N];

void update(int v, int l, int r, int ind, int val) {
    if(l==r) {
        tree[v] = min(tree[v], val);
        return;
    }
    if(ind<l || ind>r) return;
    int mid = (l+r)/2;
    update(2*v+1, l, mid, ind, val);
    update(2*v+2, mid+1, r, ind, val);
    tree[v] = min(tree[2*v+1], tree[2*v+2]);
}

int query(int v, int l, int r, int L, int R) {
    if(l>=L && r<=R) return tree[v];
    if(l>R || r<L) return inf;
    int mid = (l+r)/2;
    return min(query(2*v+1, l, mid, L, R), query(2*v+2, mid+1, r, L, R));
}



int n, q;
 
void solve() {
    cin >> n >> q;
    for(int i=0;i<4*(n+2);i++) tree[i] = inf;

    set<int> st;
    for(int i=0;i<n+2;i++) st.insert(i);

    while(q--) {
        int t;
        cin >> t;
        if(t) {
            int j;
            cin >> j;
            if(st.find(j)==st.end()) {
                cout << "NO\n";
                continue;
            }
            auto it = st.find(j);
            int cur = *it;
            --it;
            int l = (*it) + 1;
            it++; it++;
            int r = (*it);
            if(query(0, 0, n+1, l, cur)<r) {
                cout << "YES\n";
            } else {
                cout << "N/A\n";
            }
        } else {  
            int l, r, x;
            cin >> l >> r >> x;
            if(!x) {
                auto it = st.lower_bound(l);
                vector<int> healthy;
                while(it!=st.end() && *it<=r) {
                    healthy.push_back(*it);
                    it++;
                }
                for(int x: healthy) st.erase(x);
            } else {
                update(0, 0, n+1, l, r);
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