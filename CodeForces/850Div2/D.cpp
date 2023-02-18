/**
*    author:  lazyhash(yashkundu)
*    created: 12 Feb, 2023 | 16:28:44
**/
#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <tuple>
 
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
 
 
void solve() {
    int m;
    cin >> m;
    map<char, int> mp = {{'w', 0}, {'i', 1}, {'n', 2}};

    vector<vector<int>> edges(3, vector<int>(3, 0));
    
    vector<tuple<int, char, int, char>> ops;
    vector<pair<int, char>> extras[3][3];

    for(int i=0;i<m;i++) {
        string s;
        cin >> s;
        if(s[0]==s[1] && s[1]==s[2]) {
            int x = mp[s[0]];
            edges[(x+1)%3][x]++;
            extras[(x+1)%3][x].push_back({i+1, s[0]});
            edges[(x+2)%3][x]++;
            extras[(x+2)%3][x].push_back({i+1, s[0]});
        } else if(s[0]==s[1]) {
            edges[3 - mp[s[2]] - mp[s[0]]][mp[s[0]]]++;
            extras[3 - mp[s[2]] - mp[s[0]]][mp[s[0]]].push_back({i+1, s[0]});
        } else if(s[1]==s[2]) {
            edges[3 - mp[s[2]] - mp[s[0]]][mp[s[1]]]++;
            extras[3 - mp[s[2]] - mp[s[0]]][mp[s[1]]].push_back({i+1, s[1]});
        } else if(s[0]==s[2]) {
            edges[3 - mp[s[1]] - mp[s[0]]][mp[s[0]]]++;
            extras[3 - mp[s[2]] - mp[s[0]]][mp[s[0]]].push_back({i+1, s[0]});
        }
    }


    int ans = 0;
    for(int i=0;i<=2;i++) {
        int e = min(edges[i][(i+1)%3], edges[(i+1)%3][i]);
        ans += e;
        edges[i][(i+1)%3] -= e;
        edges[(i+1)%3][i] -= e;
    }

    for(int i=0;i<=2;i++) {
        assert(edges[i][(i+1)%3]==edges[(i+1)%3][(i+2)%3]);
        assert(edges[(i+1)%3][i]==edges[(i+2)%3][(i+1)%3]);
    }

    assert(edges[0][1]==0 || edges[1][0]==0);
    ans += 2*edges[0][1] + 2*edges[1][0];

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