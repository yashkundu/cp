/**
*   author: lazyhash(yashkundu)
*   created: 24 Sep, 2023 | 15:31:53
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


struct MaxSegTree{
    vector<int> tree;
    int n;
    MaxSegTree(int n) {
        this->n = n;
        tree.assign(4*n, 0);
    }
    void update(int ind, int val) {
        update(0, n-1, 0, ind, val);
    }
    void update(int nodeL, int nodeR, int node, int ind, int val) {
        if(ind<nodeL || ind>nodeR) return;
        if(nodeL==nodeR) {
            tree[node] = val;
            return;
        }
        int mid = (nodeL+nodeR)>>1;
        update(nodeL, mid, 2*node+1, ind, val), update(mid+1, nodeR, 2*node+2, ind, val);
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }
    int query(int qL, int qR) {
        return query(0, n-1, 0, qL, qR);
    }
    int query(int nodeL, int nodeR, int node, int qL, int qR) {
        if(nodeL>qR || nodeR<qL) return 0;
        if(nodeL>=qL && nodeR<=qR) return tree[node];
        int mid = (nodeL+nodeR)>>1;
        return max(query(nodeL, mid, 2*node+1, qL, qR), query(mid+1, nodeR, 2*node+2, qL, qR));
    }
};

struct SumSegTree{
    vector<int> tree;
    int n;
    SumSegTree(int n) {
        this->n = n;
        tree.assign(4*n, 0);
    }
    void increment(int ind, int inc) {increment(0, n-1, 0, ind, inc);}
    void increment(int nodeL, int nodeR, int node, int ind, int inc) {
        if(ind<nodeL || ind>nodeR) return;
        if(nodeL==nodeR) {
            tree[node] += inc;
            return;
        }
        int mid = (nodeL+nodeR)>>1;
        increment(nodeL, mid, 2*node+1, ind, inc), increment(mid+1, nodeR, 2*node+2, ind, inc);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    int query(int qL, int qR) {return query(0, n-1, 0, qL, qR);}
    int query(int nodeL, int nodeR, int node, int qL, int qR) {
        if(nodeL>qR || nodeR<qL) return 0;
        if(nodeL>=qL && nodeR<=qR) return tree[node];
        int mid = (nodeL+nodeR)>>1;
        return query(nodeL, mid, 2*node+1, qL, qR) + query(mid+1, nodeR, 2*node+2, qL, qR);
    }
};

const int N = 1e6+1000;

struct Query{
    int l, r, id;
    Query(int l, int r, int id): l(l), r(r), id(id) {}
    bool operator<(const Query &q) const {
        return l<q.l;
    }
};


vector<int> pos[N];
vector<pair<int, int>> pts;
vector<int> cnt(N, 0);


 
void solve() {
    int n, q;
    cin >> n >> q;


    vector<int> a(n);
    for(int &x: a) {
        cin >> x;
        cnt[x]++;
    }

    for(int i=1;i<=n;i++) cnt[i] += cnt[i-1];

    for(int i=0;i<n;i++) {
        pos[a[i]].push_back(i);
    }

    MaxSegTree maxTree(n);

    for(int x=1;x<=n;x++) {
        for(int i=0;i+1<pos[x].size();i++) {
            int leftInd = pos[x][i];
            int rightInd = pos[x][i+1];
            leftInd++;
            rightInd--;
            if(leftInd>rightInd) {
                pts.emplace_back(0, x);
                continue;
            }
            int maxVal = maxTree.query(leftInd, rightInd);
            pts.emplace_back(maxVal, x);
        }
        for(int i=0;i<pos[x].size();i++) maxTree.update(pos[x][i], x);
    }



    vector<int> ans(q);

    vector<Query> queries;

    for(int i=0;i<q;i++) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(l, r, i);
    }

    sort(queries.begin(), queries.end());
    sort(pts.begin(), pts.end());

    SumSegTree sumTree(n+1);

    int ptr = 0;
    for(auto q: queries) {
        while(ptr < pts.size() && pts[ptr].first<q.l) {
            sumTree.increment(pts[ptr].second, 1);
            ptr++;
        }
        ans[q.id] += sumTree.query(q.l, q.r);
    }

    for(auto q: queries) {
        int len = cnt[q.r] - ((q.l==0)?0:cnt[q.l-1]);
        ans[q.id] = len - ans[q.id];
    }

    for(int i=0;i<q;i++) {
        cout << ans[i] << "\n";
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