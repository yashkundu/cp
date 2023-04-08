/**
*   author: lazyhash(yashkundu)
*   created: 23 Feb, 2023 | 08:50:38
**/
#include <iostream>
#include <vector>
 
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

int n;
 
vector<ll> calc(vector<int> &h) {
    vector<ll> ans(n);
    vector<pair<int, int>> v;

    int left = 0;
    int rem = 0;
    ll tot = 0;

    for(int i=0;i<n;i++) {
        int x = h[i];
        while(i-rem >= x) {
            rem++;
            tot -= v[left].first;
            v[left].second--;
            if(v[left].second==0) left++;            
        }
        int cur = x - (i-rem+1);
        int cur_num = 1;
        // tot += x-(i-rem);
        while(v.size()>left) {
            auto p = v.back();
            if(p.first>=cur) {
                tot -= 1LL*p.first*p.second;
                cur_num += p.second;
                v.pop_back();
            } else {
                break;
            }
        }
        v.push_back({cur, cur_num});
        tot += 1LL*cur*cur_num;
        ans[i] = tot + 1LL*(i+1-rem)*(i+2-rem)/2;
    }
    ll pre = 0;

    for(int i=0;i<n;i++) {
        pre += h[i];
        ans[i] = pre - ans[i];
    }

    return ans;

}

 
void solve() {
    cin >> n;
    vector<int> h(n);
    for(int &x: h) cin >> x;
    vector<int> h2 = h;
    reverse(h2.begin(), h2.end());

    vector<ll> ans1 = calc(h);
    vector<ll> ans2 = calc(h2);

    ll ans = 1e18;

    for(int i=0;i<n;i++) ans = min(ans, h[i] + ans1[i] + ans2[n-1-i]);

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