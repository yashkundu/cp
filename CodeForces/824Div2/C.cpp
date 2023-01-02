/**
*    author:  lazyhash(yashkundu)
*    created: 01 Jan,2023 | 13:20:29
**/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> par(26, 0), cnt(26, 1);
vector<bool> in(26, false);

int getPar(int v) {
    if(par[v]==v) return v;
    return getPar(par[v]);
}

bool merge(int u, int v) {
    int pu = getPar(u);
    int pv = getPar(v);
    if(pu==pv) {
        if(cnt[pu]!=26) return false;
    }
    par[u] = v;
    cnt[pv] += cnt[pu];
    in[v] = true;
    return true;
}



void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    iota(par.begin(), par.begin()+26, 0);
    cnt.assign(26, 1);
    in.assign(26, false);

    string ans = "";

    for(int i=0;i<n;i++) {
        int k = str[i] - 'a';
        if(par[k]!=k) {
            ans += ('a'+ par[k]);
            continue;
        }
        for(int i=0;i<26;i++) {
            if(i==k) continue;
            if(!in[i] && merge(k, i)) break; 
        }
        ans += ('a' + par[k]);
    }


    cout << ans << "\n";



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