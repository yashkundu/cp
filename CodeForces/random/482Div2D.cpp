/**
*   author: lazyhash(yashkundu)
*   created: 18 May, 2024 | 22:36:43
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e5+10;


struct Node{
    int min;
    Node* bit[2];
    Node() {
        min = MAXN;
        bit[0] = bit[1] = nullptr;
    }
};

vector<int> di[MAXN];
Node* root[MAXN];

void init() {
    for(int i=1;i<MAXN;i++) {
        for(int j=i;j<MAXN;j+=i) {
            di[j].push_back(i);
        }
        root[i] = new Node();
    }
}

void add(int k, int u) {
    Node* cur = root[k];
    cur->min = min(cur->min, u);

    for(int j=18;j>=0;j--) {
        int b = (u>>j&1);
        if(cur->bit[b]==nullptr) cur->bit[b] = new Node();
        cur = cur->bit[b];
        cur->min = min(cur->min, u);
    }

}

int query(int x, int k, int s) {
    Node* cur = root[k];
    if(x%k || x+cur->min>s) return -1;

    int res = 0;
    for(int j=18;j>=0;j--) {
        int b = (x>>j&1);
        if(cur->bit[b^1]!=nullptr && cur->bit[b^1]->min+x<=s) {
            res += ((b^1)<<j);
            cur = cur->bit[b^1];
        } else {
            res += (b<<j);
            cur = cur->bit[b];
        }
    }
    return res;
}


int q, u, x, k, s;
bool chk[MAXN];
 
void solve() {
    init();
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            cin >> u;
            if(!chk[u]) {
                chk[u] = true;
                for(int k: di[u]) add(k, u);
            }
        } else {
            cin >> x >> k >> s;
            cout << query(x, k, s) << "\n";
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