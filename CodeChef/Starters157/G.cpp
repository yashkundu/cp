/**
*    author:  lazyhash(yashkundu)
*    created: 26 Oct, 2024 | 12:15:58
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <stack>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)2e5+10;


pair<ll, int> t[4*MAXN];
int lazy[4*MAXN];

pair<ll, int> merge(pair<ll, int> p1, pair<ll, int> p2) {
    return {p1.first+p2.first, p1.second+p2.second};
}

void build(int v, int tl, int tr) {
    lazy[v] = 0;
    if(tl==tr) {
        t[v] = {0LL, 1};
        return;
    }
    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = merge(t[2*v], t[2*v+1]);
}


void push(int v) {
    if(!lazy[v]) return;
    t[2*v].first += 1LL*lazy[v]*t[2*v].second;
    lazy[2*v] += lazy[v];
    t[2*v+1].first += 1LL*lazy[v]*t[2*v+1].second;
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}

void updateone(int v, int tl, int tr, int pos) {
    if(tl==tr) {
        t[v].second = 0;
        return;
    }
    push(v);
    int tm = (tl+tr)/2;
    if(pos<=tm) updateone(2*v, tl, tm, pos);
    else updateone(2*v+1, tm+1, tr, pos);
    t[v] = merge(t[2*v], t[2*v+1]);
}

void udpaterange(int v, int tl, int tr, int l, int r) {
    if(l>r) return;
    if(l==tl && r==tr) {
        t[v].first += t[v].second;
        lazy[v] += 1;
        return;
    }
    push(v);
    int tm = (tl+tr)/2;
    udpaterange(2*v, tl, tm, l, min(tm, r));
    udpaterange(2*v+1, tm+1, tr, max(l, tm+1), r);
    t[v] = merge(t[2*v], t[2*v+1]);
}


ll querytree(int v, int tl, int tr, int l, int r) {
    if(l>r) return 0LL;
    if(l==tl && r==tr) return t[v].first;
    push(v);
    int tm = (tl+tr)/2;
    return querytree(2*v, tl, tm, l, min(r, tm)) + querytree(2*v+1, tm+1, tr, max(tm+1, l), r);
}


int n, q;
ll a[MAXN];

vector<pair<int,int>> qs[MAXN];
ll ans[MAXN] = {0};
int lft[MAXN], rght[MAXN];
vector<int> inactive[MAXN];


int x, y;
 
void solve() {

    cin >> n >> q;


    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) a[i] += a[i-1];

    for(int i=1;i<=n;i++) qs[i].clear();

    for(int i=0;i<q;i++) {
        cin >> x >> y;
        qs[x].push_back({y, i});
    }


    stack<int> st;
    for(int i=0;i<=n;i++) {
        while(!st.empty() && a[st.top()]<=a[i]) st.pop();
        if(st.empty()) lft[i] = -1;
        else lft[i] = st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=n;i>=0;i--) {
        while(!st.empty() && a[st.top()]>=a[i]) st.pop();
        if(st.empty()) rght[i] = n+1;
        else rght[i] = st.top();
        st.push(i);
    }

    for(int i=0;i<=n;i++) inactive[i].clear();
    for(int i=1;i<=n;i++) {
        if(lft[i]>=0) inactive[lft[i]].push_back(i);
    }

    build(1, 0, n);

    for(int l=n;l>0;l--) {
        for(int x: inactive[l]) updateone(1, 0, n, x);
        udpaterange(1, 0, n, l, rght[l-1]-1);
        for(auto qy: qs[l]) {
            ans[qy.second] = querytree(1, 0, n, l, qy.first);
        }
    }

    for(int i=0;i<q;i++) cout << ans[i] << "\n";
    
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