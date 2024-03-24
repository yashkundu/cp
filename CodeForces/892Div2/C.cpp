/**
*   author: lazyhash(yashkundu)
*   created: 02 Sep, 2023 | 22:20:32
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <stack>
 
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

    // iterate over the max elements
    ll ans = 0;
    for(int mx=n*n;mx>=n;mx--) {
        ll curAns = 0;
        int curMax = 0;
        // mx will be the maximum element of the array p_i*i
        // the element with value i, can be placed in place [1..mx/i]
        // take a set of all the positions and then iterate from n to 1 to find the maximal place of each element
        // will take O(n^3logn) or O(n^3) by using stacks

        // Will store for each index, the elements whose maximal possible index is that index
        vector<vector<int>> v;
        v.assign(n, vector<int>());
        for(int el=n;el>0;el--) {
            int ind = min(mx/el, n);
            v[ind-1].push_back(el);
        }
        stack<int> s;
        bool badCase = false;
        for(int i=0;i<n;i++) {
            s.push(i+1);
            for(int el: v[i]) {
                if(s.empty()) {
                    badCase = true;
                    break;
                }
                int maxInd = s.top();
                s.pop();
                curMax = max(el*maxInd, curMax);
                curAns += el*maxInd;
            }
            if(badCase) break;
        }
        if(badCase) continue;
        curAns -= curMax;
        ans = max(curAns, ans);
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/