/**
*    author:  lazyhash(yashkundu)
*    created: 03 Jul, 2024 | 10:28:00
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5)+10;
const int LOG = 20;


struct Node{
    Node* nxt[2];
    Node() {
        nxt[0] = nullptr;
        nxt[1] = nullptr;
    }
};


void insert(Node* root, int x) {
    for(int j=LOG-1;j>=0;j--) {
        int bit = (x>>j)&1;
        if(root->nxt[bit]==nullptr) root->nxt[bit] = new Node();
        root = root->nxt[bit];
    }
}

int maxxor(Node *root, int x) {
    for(int j=LOG-1;j>=0;j--) {
        int bit = (x>>j)&1;
        if(root->nxt[bit^1]!=nullptr) bit = bit^1;
        x ^= (bit<<j);
        root = root->nxt[bit];
    }
    return x;
}

int n;
int a[MAXN];

 
void solve() {
    Node* root = new Node();
    cin >> n;
    for(int i=0;i<n-1;i++) cin >> a[i];
    for(int i=1;i<n-1;i++) a[i] ^= a[i-1];

    for(int i=0;i<n-1;i++) insert(root, a[i]);

    for(int first=0;first<n;first++) {
        int mx = maxxor(root, first);
        if(mx<n) {
            cout << first << " ";
            for(int i=0;i<n-1;i++) cout << (first^a[i]) << " ";
            cout << "\n";
            return;
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/