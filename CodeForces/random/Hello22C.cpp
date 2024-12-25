/**
*    author:  lazyhash(yashkundu)
*    created: 09 Oct, 2024 | 16:47:11
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> p;

int query(int i) {
    cout << "? " << i << endl;
    int x;
    cin >> x;
    if(x==0) exit(0);
    return x;
}


void output() {
    cout << "! ";
    for(int i=1;i<=n;i++) cout << p[i] << " ";
    cout << endl;
}

vector<int> v;
 
void solve() {
    cin >> n;
    p.resize(n+1);

    fill(p.begin(), p.end(), 0);

    v.clear();


    int cnt = 0;

    int ptr = 1;
    while(true) {
        while(ptr<=n && p[ptr]) ptr++;
        if(ptr>n) break;
        v.clear();
        int del = cnt-1;
        int x = query(ptr);
        cnt++;
        v.push_back(x);
        while(x=query(ptr), cnt++, x!=v[0]) v.push_back(x);
        int m = v.size();
        int ind = (m - del%m)%m;
        for(int i=0;i<m;i++) {
            p[ptr] = v[(i+ind)%m];
            ptr = v[(i+ind)%m];
        }
    }

    output();








    


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