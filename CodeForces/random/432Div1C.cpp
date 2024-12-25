/**
*    author:  lazyhash(yashkundu)
*    created: 11 Jun, 2024 | 19:12:22
**/
#include <iostream>
#include <vector>
#include <map> 

using namespace std;
 
typedef long long ll;
typedef long double ld;
 

int n, x;

map<int, int> mask, nim, mark;

int transition(int mask, int i) {
    return (mask>>i)|(mask & ((1<<i)-1));
}


int getNimValue(int mask) {
    if(mask==0) return 0;
    if(nim.find(mask)!=nim.end()) return nim[mask];
    int mxBit = 32 - __builtin_clz(mask);
    vector<int> tmp;
    for(int i=1;i<mxBit;i++) {
        tmp.push_back(getNimValue(transition(mask, i)));
    }
    for(int x: tmp) mark[x] = mask;
    while(mark[nim[mask]]==mask) nim[mask]++;
    return nim[mask];
}

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x;
        for(int j=2;j*j<=x;j++) {
            if(x%j==0) {
                int cnt = 0;
                while(x%j==0) {
                    cnt++;
                    x /= j;
                }
                mask[j] |= (1<<cnt);
            }
        }
        if(x>1) mask[x] |= (1<<1);
    }

    int s = 0;
    for(auto p: mask) 
        s ^= getNimValue(p.second);

    cout << (s?"Mojtaba": "Arpa") << "\n";


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