/**
*    author:  lazyhash(yashkundu)
*    created: 21 Sep, 2024 | 17:37:54
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
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x; 
}

void output(string s) {
    cout << "! " << s << endl;
    return;
}

int n;
 
void solve() {
    cin >> n;
    if(n==1) {
        if(query("0")) output("0");
        else output("1");
        return;
    }

    string s="";
    if(query("00")) s = "00";
    else if(query("11")) s = "11";
    else {
        for(int i=0;i<n;i++) {
            if(i&1) s += "0";
            else s += "1";
        }
        if(query(s)) {
            output(s);
            return;
        }
        s = "";
        for(int i=0;i<n;i++) {
            if(i&1) s += "1";
            else s += "0";
        }
        output(s);
        return;
    }


    while(s.size()<n) {
        if(query(s+"0")) s += "0";
        else if(query(s+"1")) s += "1";
        else break;
    }

    while(s.size()<n) {
        if(query("0"+s)) s = "0" + s;
        else s = "1" + s;
    }

    output(s);

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