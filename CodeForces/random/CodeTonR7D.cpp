/**
*    author:  lazyhash(yashkundu)
*    created: 02 Jul, 2024 | 18:56:57
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set> 

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q;
vector<int> a;
 
set<int> pos;

void solve() {
    cin >> n >> q;
    a.resize(n);
    pos.clear();

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]==1) pos.insert(i);
    }

    while(q--) {
        int op;
        cin >> op;
        if(op==1) {
            int v; cin >> v;
            int num = pos.size();
            if((v-num)&1) {
                if(num==0) cout << "NO";
                else {
                    int s1 = 2*(*pos.rbegin()) - (num-1);
                    int s2 = 2*(n-*pos.begin()-1) - (num-1);
                    if(v<=max(s1, s2)) cout << "YES";
                    else cout << "NO";
                }
            } else {
                if(v<=2*n - num) cout << "YES";
                else cout << "NO";
            }
            cout << "\n";
        } else {
            int ind;
            cin >> ind;
            ind--;
            pos.erase(ind);
            cin >> a[ind];
            if(a[ind]==1) pos.insert(ind);
        }
    }


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