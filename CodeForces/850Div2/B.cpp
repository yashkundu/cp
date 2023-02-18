/**
*    author:  lazyhash(yashkundu)
*    created: 12 Feb, 2023 | 15:52:15
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
struct Seg{
    int l, r;
    Seg(int x, int y): l(x), r(y) {}
    Seg operator^=(const Seg &s) {
        l = max(l, s.l);
        r = min(r, s.r);
        return *this;
    }
    friend ostream& operator<<(ostream &out, const Seg &s) {
        out << "< " <<  s.l << ", " << s.r << " >";
        return out;
    }
};
 
void solve() {
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    Seg s(-2e9, 2e9);
    for(int i=0;i<n;i++) {
        int x1 = b[i]-h-a[i]+w, x2 = b[i]+h-a[i]-w;
        Seg cur_seg = Seg(min(x1, x2), max(x1, x2));
        s ^= cur_seg;
    }

    if(s.r>=s.l) {
        cout << "YES";
    } else {
        cout << "NO";
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