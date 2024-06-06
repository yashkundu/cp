/**
*   author: lazyhash(yashkundu)
*   created: 01 May, 2024 | 13:00:09
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
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


const int N = 1e5+10;
int a[N], b[N], delta[N];
ll pref[N];
vector<pair<int, int>> segs;

const ll inf = 1e18+10;


struct MaxSeg{
    int n;
    vector<ll> tree;
    MaxSeg(int n) {
        this->n = n;
        tree.resize(4*n);
        fill(tree.begin(), tree.end(), -inf);
    }

    void update(int ind, ll val) {
        update(0, 0, n-1, ind, val);
    }

    void update(int v, int l, int r, int ind, ll val) {
        if(ind>r || ind<l) return;
        if(l==r) {
            tree[v] = max(tree[v], val);
            return;
        }
        int mid = (l+r)/2;
        update(2*v+1, l, mid, ind, val);
        update(2*v+2, mid+1, r, ind, val);
        tree[v] = max(tree[2*v+1], tree[2*v+2]);
    }

    ll query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }

    ll query(int v, int l, int r, int ql, int qr) {
        if(l>qr || r<ql) return -inf;
        if(l>=ql && r<=qr) return tree[v];
        int mid = (l+r)/2;
        return max(query(2*v+1, l, mid, ql, qr), query(2*v+2, mid+1, r, ql, qr));
    }
};


int n, q;
 
int signum(int x) {
    if(x==0) return 0;
    else if(x>0) return 1;
    else return -1;
}

void solve() {
    cin >> n >> q;
    pref[0] = 0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) {
        delta[i] = a[i] - b[i];
        pref[i+1] = pref[i] + delta[i];
    }


    int curSign = 0;
    for(int i=0;i<n;) {
        int j = i;
        curSign = 0;
        while(j<n && (!curSign || !signum(delta[j]) || (curSign==signum(delta[j])))) {
            if(signum(delta[j])) curSign = signum(delta[j]);
            j++;
        }
        segs.push_back({i, j});
        i = j;
    }


    MaxSeg st1(n+1);
    for(int i=0;i<=n;i++) st1.update(i, pref[i]);

    MaxSeg st2(segs.size());
    for(int i=0;i<segs.size();i++) st2.update(i, abs(pref[segs[i].second]-pref[segs[i].first]));


    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(pref[r+1]-pref[l]) {
            cout << "-1\n";
            continue;
        }
        if(st1.query(l+1, r+1)-pref[l]>0) {
            cout << "-1\n";
            continue;
        }


        int ind1 = (upper_bound(segs.begin(), segs.end(), make_pair(l, int(1e9))) - segs.begin()) - 1;
        int ind2 = (upper_bound(segs.begin(), segs.end(), make_pair(r, int(1e9))) - segs.begin()) - 1;


        if(ind1==ind2) {
            cout << abs(pref[r+1]-pref[l]) << "\n";
        } else {
            ll mx = -inf;
            if(ind2-ind1>1) {
                mx = st2.query(ind1+1, ind2-1);
            }
            mx = max(mx, abs(pref[segs[ind1].second] - pref[l]));
            mx = max(mx, abs(pref[r+1] - pref[segs[ind2].first]));
            cout << mx << "\n";
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