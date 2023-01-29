/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jan, 2023 | 21:12:55
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

struct node{
    node* nxt[10];
}; 

void insert(node* root, vector<int>& v) {
    node* tmp = root;
    for(int &x: v) {
        if(!tmp->nxt[x]) tmp->nxt[x] = new node();
        tmp = tmp->nxt[x];
    }
}

int calc(node* root, vector<int> &v) {
    int cnt = 0;
    node* tmp = root;
    for(int &x: v) {
        if(tmp->nxt[x]) {
            cnt++;
            tmp = tmp->nxt[x];
        }
        else break;
    }
    return cnt;
}

void reduce(vector<int> &v, vector<int> &d) {
    vector<int> ind(10, -1);
    for(int i=0;i<int(v.size());i++) ind[v[i]] = i;
    for(int i=0;i<int(d.size());i++) d[i] = ind[i];
}
 
void solve() {
    int n, m;
    cin >> n >> m;

    node* trie = new node();

    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> d(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v[i][j];
            v[i][j]--;
        }
        reduce(v[i], d[i]);
        insert(trie, d[i]);
    }

    for(int i=0;i<n;i++) {
        cout << calc(trie, v[i]) << " ";
    }
    cout << "\n";



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