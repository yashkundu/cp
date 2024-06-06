/**
*   author: lazyhash(yashkundu)
*   created: 02 Jun, 2024 | 10:00:23
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


int n, m;
int a, b;

string s;
string concatS;


set<string> st[10][200];
pair<string, string> flstr[200];
 
void solve() {
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> s;
        for(int k=1;k<10;k++) {
            for(int j=0;j+k-1<s.size();j++) {
                st[k][i].insert(s.substr(j, k));
            }
        }
        flstr[i].first = s.substr(0, 9);
        flstr[i].second = s.substr(max(0, int(s.size())-9), min(9, int(s.size())));
    }


    cin >> m; 

    for(int i=0;i<m;i++) {
        cin >> a >> b;
        a--, b--;
        for(int k=1;k<10;k++) {
            for(string x: st[k][a]) st[k][i+n].insert(x);
            for(string x: st[k][b]) st[k][i+n].insert(x);
        }
        concatS = flstr[a].second + flstr[b].first;
        for(int k=1;k<10;k++) {
            for(int j=0;j+k-1<concatS.size();j++) {
                st[k][i+n].insert(concatS.substr(j, k));
            }
        }
        flstr[i+n].first = (flstr[a].first+flstr[b].first).substr(0, 9);
        concatS = flstr[a].second + flstr[b].second;
        flstr[i+n].second = concatS.substr(max(0, int(concatS.size()) - 9), min(9, int(concatS.size())));


        if(st[1][i+n].size()==2) {
            for(int k=9;k>0;k--) {
                if(st[k][i+n].size()==(1<<k)) {
                    cout << k << "\n";
                    break;
                }
            }
        } else {
            cout << "0\n";
        }
    }

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/