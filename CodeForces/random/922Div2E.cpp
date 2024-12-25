/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jun, 2024 | 15:49:10
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


char query(int i) {
    cout << "? " << i << endl;
    char ch;
    cin >> ch;
    return ch;
}


int n;
int pos1, posn;
vector<int> res;


void calc(int l, int r, vector<int> &v) {
    int m = (l+r)/2;
    vector<int> lh, rh;
    for(int i=0;i<v.size();i++) {
        char ch = query(v[i]);
        if(ch=='>') {
            rh.push_back(v[i]);
            query(pos1);
        } else if(ch=='<') {
            lh.push_back(v[i]);
            query(posn);
        } else {
            res[v[i]] = m;
        }
    }
    if(!lh.empty()) {
        int m2 = (l+m-1)/2;
        for(int k=0;k<m-m2;k++) query(pos1);
        calc(l, m-1, lh);
        query(posn);
    }
    if(!rh.empty()) {
        int m2 = (1+m+r)/2;
        for(int k=0;k<m2-m;k++) query(posn);
        calc(m+1, r, rh);
    }
}

 
void solve() {
    cin >> n;
    
    pos1 = -1; 
    for(int i=1;i<=n;i++) {
        char ch = query(i);
        if(ch=='<') i--;
        else if(ch=='=') pos1 = i;
        else if(pos1!=-1) query(pos1);
    }

    posn = -1;
    for(int i=1;i<=n;i++) {
        char ch = query(i);
        if(ch=='>') i--;
        else if(ch=='=') posn = i;
        else if(posn!=-1) query(posn);
    }

    res.resize(n+1);
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);

    int m = (1+n)/2;
    for(int k=0;k<n-m;k++) query(pos1);

    calc(1, n, v);

    cout << "! ";
    for(int i=1;i<=n;i++) cout << res[i] << " ";
    cout << endl;






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