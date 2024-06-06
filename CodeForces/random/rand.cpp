#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



const int N = 51;
string s[N];

int n;

string finalAns = "";


bool check(string curStr, int k) {
    if(curStr.size()==k) {
        for(int i=0;i<n;i++) {
            if(s[i].find(curStr)!=string::npos) return false;
        }
        finalAns = curStr;
        return true;
    } 
    for(int i=0;i<26;i++) {
        curStr += (char)('a'+i);
        if(check(curStr, k)) return true;
        curStr.pop_back();
    }
    return false;
}




 
void solve() {
    cin >> n;

    for(int i=0;i<n;i++) cin >> s[i];

    for(int i=1;i<=3;i++) {
        if(check("", i)) break;
    }

    cout << finalAns << "\n";

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
