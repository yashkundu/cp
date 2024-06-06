/**
*   author: lazyhash(yashkundu)
*   created: 19 May, 2024 | 14:22:14
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

using ms = multiset<int>;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+5;

struct Node{
    bool term;
    Node* nxt[26];
    Node() {
        for(int i=0;i<26;i++) nxt[i] = nullptr;
        term = false;
    }
} *root;


void add(string s) {
    int m = s.size();
    Node* cur = root;
    for(int i=0;i<m;i++) {
        if(cur->nxt[s[i]-'a']==nullptr) cur->nxt[s[i]-'a'] = new Node();
        cur = cur->nxt[s[i]-'a'];
    }
    cur->term = true;
}

ms* merge(ms* a, ms* b) {
    if(a->size()>b->size()) swap(a, b);
    for(int x: *a) b->insert(x);
    delete a;
    return b;
}

ms* calc(Node* cur, int dep) {
    ms* ans = new multiset<int>();
    for(int i=0;i<26;i++) if(cur->nxt[i]!=nullptr) {
        ms* tAns = calc(cur->nxt[i], dep+1);
        ans = merge(ans, tAns);
    }
    if(cur->term) {
        ans->insert(dep);
    } else if(dep) {
        ans->erase(prev(ans->end()));
        ans->insert(dep);
    }
    return ans;
}


int n;
 
void solve() {
    root = new Node();
    cin >> n;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        add(s);
    }
    ms* s = calc(root, 0);
    ll ans = 0;
    for(int x: *s) ans += x;
    cout << ans << "\n";
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