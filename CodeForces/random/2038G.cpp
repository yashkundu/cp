/**
*    author:  lazyhash(yashkundu)
*    created: 22 Nov, 2024 | 22:41:24
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int query(string s) {
    cout << "1 " << s <<  endl;
    int x;
    cin >> x;
    if(x==-1) exit(0);
    return x;
}

void output(int ind, char ch) {
    cout << "0 " << ind << " " << ch << endl;
    int x;
    cin >> x;
    if(x==-1) exit(0);
    return;
}
 
int n;

void solve() {
    cin >> n;

    int num = query("0");

    if(!num) {
        output(1, '1');
        return;
    }

    int x = query("01") + query("00");

    if(x==num) output(n, '1');
    else output(n, '0');



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