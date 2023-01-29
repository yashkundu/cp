/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jan, 2023 | 11:44:41
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    vector<int> odd, even;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]&1) odd.push_back(i+1);
        else even.push_back(i+1);
    }
    

    if(odd.empty()) {
        cout << "NO\n";
        return;
    }

    if(n==3 && even.size()==1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    if(even.size()<=1) {
        cout << odd[0] << " " << odd[1] << " " << odd[2] << "\n";
    } else {
        cout << even[0] << " " << even[1] << " " << odd[0] << "\n";
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