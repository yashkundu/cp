/**
*    author:  lazyhash(yashkundu)
*    created: 07 Dec, 2024 | 12:43:40
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map> 
#include <set>
#include <stack>
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

const int LG = 19;
const int MAXN = (int)2e5+10;


struct SegTree{
    vector<ll> tree, lazy;
    int n;

    SegTree(int n) {
        this->n = n;
        tree.resize(4*n);
        fill(tree.begin(), tree.end(), 0);
        lazy.resize(4*n);
        fill(lazy.begin(), lazy.end(), -1);
    }

    void propagate(int v, int tl, int tr) {
        if(lazy[v]!=-1) {
            int tm = (tl+tr)/2;
            lazy[2*v+1] = lazy[2*v+2] = lazy[v];
            tree[2*v+1] = lazy[v]*(tm-tl+1);
            tree[2*v+2] = lazy[v]*(tr-tm);
            lazy[v] = -1;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int val) {
        if(l>r) return;
        if(tl==l && tr==r) {
            tree[v] = 1LL*val*(tr-tl+1);
            lazy[v] = val;
            return;
        }
        propagate(v, tl, tr);
        int tm = (tl+tr)/2;
        update(2*v+1, tl, tm, l, min(tm, r), val);
        update(2*v+2, tm+1, tr, max(tm+1, l), r, val);
        tree[v] = tree[2*v+1] + tree[2*v+2];
    }

    void update(int l, int r, int val) {
        update(0, 0, n-1, l, r, val);
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if(l>r) return 0LL;
        if(tl==l && tr==r) {
            return tree[v];
        }
        propagate(v, tl, tr);
        int tm = (tl+tr)/2;
        return query(2*v+1, tl, tm, l, min(tm, r)) + query(2*v+2, tm+1, tr, max(tm+1, l), r);
    }

    ll query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }

};


int n, k, q;
int a[MAXN], ans[MAXN];
ll res[MAXN];

map<int, int> freq;
multiset<int> ms;


vector<pair<pair<int, int>, int>> queries;


int l, r;

 
void solve() {
    cin >> n >> k >> q;
    for(int i=0;i<n;i++) ans[i] = 0; 


    ms.clear();
    freq.clear();
    queries.clear();

    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i] -= i;
    }

    for(int i=0;i<k;i++) {
        freq[a[i]]++;
    }

    for(auto it: freq) ms.insert(it.second);

    for(int i=0;i+k-1<n;i++) {
        ans[i] = k - *ms.rbegin();
        ms.extract(freq[a[i]]);
        freq[a[i]]--;
        ms.insert(freq[a[i]]);
        if(i+k<n) {
            ms.extract(freq[a[i+k]]);
            freq[a[i+k]]++;
            ms.insert(freq[a[i+k]]);
        }
    }


    SegTree stree(n);

    for(int i=0;i<q;i++) {
        cin >> l >> r;
        l--, r--;
        r = r-k+1;
        queries.push_back({{l, r}, i});
    }



    sort(queries.rbegin(), queries.rend());
    stack<int> st;

    int ptr = n-k;

    for(auto q: queries) {
        while(ptr>=q.first.first) {
            while(!st.empty() && ans[st.top()]>=ans[ptr]) st.pop();
            int nxt = n;
            if(!st.empty()) nxt = st.top();
            stree.update(ptr, nxt-1, ans[ptr]);
            st.push(ptr);
            ptr--;
        }
        res[q.second] = stree.query(q.first.first, q.first.second);
    }


    for(int i=0;i<q;i++) cout << res[i] << "\n";






    







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