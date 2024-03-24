/**
*   author: lazyhash(yashkundu)
*   created: 15 Nov, 2023 | 23:05:41
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <deque>
 
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
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(n&1) {
        cout << "-1\n";
        return;
    }

    deque<char> dq;

    for(int i=0;i<n;i++) dq.push_back(s[i]);
    int removed = 0;

    vector<int> ans;

    while(ans.size()<=300 && dq.size()>0) {
        if(dq.front()!=dq.back()) {
            dq.pop_front();
            dq.pop_back();
            removed++;
        }
        else if(dq.front()=='0') {
            ans.push_back(dq.size()+removed);
            dq.push_back('0');
            dq.push_back('1');
        } else {
            ans.push_back(removed);
            dq.push_front('1');
            dq.push_front('0');
        }
    }

    if(dq.size()) {
        cout << "-1\n";
        return;
    }

    cout << ans.size() << "\n";
    for(int x: ans) cout << x << " ";



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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/