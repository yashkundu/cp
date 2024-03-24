/**
*   author: lazyhash(yashkundu)
*   created: 16 Feb, 2024 | 17:23:47
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int N = 3e5+10;
ll tree[N];
int n, m, q;
int x[N], v[N];


void update(int ind, ll val) {
    for(;ind<=n;ind+=ind&(-ind)) tree[ind] += val;
}

ll query(int ind) {
    ll sum = 0;
    for(;ind>0;ind-=ind&(-ind)) sum += tree[ind];
    return sum;
}

ll query(int l, int r) {
    return query(r) - query(l-1);
}




 
void solve() {
    cin >> n >> m >> q;
    
    fill(x, x+n+1, 0);
    fill(v, v+n+1, 0);
    fill(tree, tree+n+1, 0);

    for(int i=0;i<m;i++) cin >> x[i];
    for(int i=0;i<m;i++) cin >> v[x[i]];


    set<int> harbours;
    for(int i=0;i<m;i++) harbours.insert(x[i]);

    debug(harbours);

    int prevHInd = 0;
    for(auto it = harbours.rbegin(); it!=harbours.rend(); it++) {
        int curHInd = *it;
        if(prevHInd) {
            debug(curHInd, prevHInd, v[curHInd]);
            ll val = v[curHInd]*1ll*(prevHInd-curHInd)*(prevHInd-curHInd-1)/2;
            update(curHInd, val);
        }
        prevHInd = curHInd;
    }

    debug(v[1], v[3], v[8]);
    debug(query(1, 1), query(3, 3), query(8, 8));


    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            int curHInd, hVal;
            cin >> curHInd >> hVal;
            v[curHInd] = hVal;
            auto it = harbours.upper_bound(curHInd);
            // change this harbour
            int nextHInd = *it;
            --it;
            int prevHInd = *it;
            ll prevVal = v[prevHInd]*1LL*(nextHInd-prevHInd)*(nextHInd-prevHInd-1)/2;
            ll newVal = v[prevHInd]*1LL*(curHInd-prevHInd)*(curHInd-prevHInd-1)/2;
            update(prevHInd, newVal-prevVal);
            harbours.insert(curHInd);
            ll curHVal = hVal*1LL*(nextHInd-curHInd)*(nextHInd-curHInd-1)/2;
            update(curHInd, curHVal);
            debug("inside 1 type query");
            debug(harbours);
            debug(v[1], v[3], v[5], v[8]);
            debug(query(1, 1), query(3, 3), query(5, 5), query(8, 8));
        } else {
            int l, r;
            cin >> l >> r;
            debug(l, r);
            ll ans = query(l, r);
            debug(ans);
            // dealing with harbours on the ends
            auto it = harbours.lower_bound(l);
            if(it!=harbours.begin()) {
                int curHInd = *it;
                --it;
                int prevHInd = *it;
                debug(prevHInd, curHInd);
                // *it .... l  ....   r
                ll del = v[prevHInd]*1LL*(curHInd-l)*(curHInd-l+1)/2;
                ans += del;
                debug(del, ans);
            }
            it = harbours.upper_bound(r);
            if(it!=harbours.end()) {
                int curHInd = *it;
                --it;
                int prevHInd = *it;
                debug(prevHInd, curHInd);
                ll del = v[prevHInd]*1LL*(curHInd-r)*(curHInd-r-1)/2;
                ans -= del;
                debug(del, ans);
            }
            cout << ans << "\n";
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