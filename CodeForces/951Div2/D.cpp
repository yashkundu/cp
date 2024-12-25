/**
*    author:  lazyhash(yashkundu)
*    created: 09 Jun, 2024 | 20:23:33
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


int n, k;
string s, tempS, newS;
 
bool check(string &s) {
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && s[j]==s[i]) j++;
        if(j-i!=k) return false;
        i = j;
    }
    return true;
}

void solve() {
    cin >> n >> k;
    cin >> s;

    if(check(s)) {
        cout << n << "\n";
        return;
    }


    for(int i=0;i<n;) {
        int j = i;
        while(j<n && s[j]==s[i]) j++;
        if(j-i!=k) {
            // this needs to be reattached in the back of s
            if(j-i<k) {
                tempS = s.substr(0, j);
                reverse(tempS.begin(), tempS.end());
                newS = s.substr(j, n-j) + tempS;
            } else {
                tempS = s.substr(0, j-k);
                reverse(tempS.begin(), tempS.end());
                newS = s.substr(j-k, n-j+k) + tempS;
            }
            if(check(newS)) {
                cout << (int)tempS.size() << "\n";
            }else {
                cout << "-1\n";
            }
            return;
        }
        i = j;
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