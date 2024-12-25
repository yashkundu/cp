/**
*    author:  lazyhash(yashkundu)
*    created: 01 Jul, 2024 | 12:53:14
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


struct Node{
    int tot;
    Node* nxt[26];
    Node() {
        tot = 0;
        for(int i=0;i<26;i++) nxt[i] = nullptr;
    }
};


void insert(Node* root, string s) {
    int n = s.size();
    for(int i=0;i<n;i++) {
        int ind = s[i] - 'a';
        if(root->nxt[ind]==nullptr) root->nxt[ind] = new Node();
        root->tot++;
        root = root->nxt[ind];
    }
    root->tot++;
}

int n;
vector<string> s, sr;

ll ans = 0;
ll tot = 0;


ll calc(Node* root, string s) {
    ll res = tot + 1LL*n*((int)s.size());
    for(int l=0;l<=s.size() && root!=nullptr;l++) {
        int diff = 0;
        if(l<s.size() && root->nxt[s[l]-'a']!=nullptr) diff = root->nxt[s[l]-'a']->tot;
        res -= 2LL*(root->tot - diff)*l;
        if(l<s.size()) root = root->nxt[s[l]-'a'];
    }
    return res;
}

 
void solve() {
    cin >> n;
    s.resize(n);
    sr.resize(n);

    tot = 0;
    ans = 0;

    for(int i=0;i<n;i++) {
        cin >> s[i];
        tot += (int)s[i].size();
        sr[i] = s[i];
        reverse(sr[i].begin(), sr[i].end());
    }

    Node* revnode = new Node();

    for(int i=0;i<n;i++) insert(revnode, sr[i]);

    ll ans = 0;

    for(int i=0;i<n;i++) {
        ans += calc(revnode, s[i]);
    }

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/