/**
*    author:  lazyhash(yashkundu)
*    created: 25 Aug, 2024 | 20:37:18
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

int n;
string s;

set<pair<int, int>> st;

string ans;

int freq[26];
 
void solve() {
    cin >> n;
    cin >> s;
    for(int i=0;i<26;i++) freq[i] = 0;

    for(int i=0;i<n;i++) freq[s[i]-'a']++;


    st.clear();

    for(int i=0;i<26;i++) {
        if(freq[i]) st.insert({freq[i], i});
    }

    ans = "";

    pair<int, int> last = {0, 0};

    for(int i=0;i<n;i++) {
        if(st.empty()) {
            for(int j=0;j<last.first;j++) ans += (char)('a'+last.second);
            break;
        }
        auto it = *st.rbegin();
        st.erase(it);
        it.first--;
        ans += (char)('a'+it.second);
        if(last.first) st.insert(last);
        last = it;
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