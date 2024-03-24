/**
*   author: lazyhash(yashkundu)
*   created: 04 Feb, 2024 | 19:53:33
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

const int N = 2e5+10;
const int A = 26;
set<int> twos, threes;
int n, m;
string s;

int tree[N];

int calcPrefixBIT(int ind) {
    int sum = 0;
    for(;ind>0;ind-=(ind&-ind)) sum += tree[ind];
    return sum;
}

void updateBIT(int ind, int val) {
    for(;ind<=n;ind+=(ind&-ind)) tree[ind] += val;
}

void resetBIT(int n) {
    for(int i=0;i<=n;i++) tree[i] = 0;
}


bool checkEqual(int i, int j) {
    // checks if s[i]==s[j] after applying all the ops
    return ((s[i-1]-'a') + calcPrefixBIT(i))%A == ((s[j-1]-'a') + calcPrefixBIT(j))%A;
}



 
void solve() {
    cin >> n >> m;
    resetBIT(n);

    cin >> s;
    twos.clear(), threes.clear();


    for(int i=0;i<n-1;i++) {
        if(s[i]==s[i+1]) twos.insert(i+1);
        if(i<n-2 && s[i]==s[i+2]) threes.insert(i+1); 
    } 

    for(int i=0;i<m;i++) {
        int type;
        cin >> type;
        if(type==1) {
            // update
            int l, r, x;
            cin >> l >> r >> x;
            x %= A;
            if(!x) continue;
            // check for corner cases and if yes remove them

            // remove conflicting threes and twos
            if(l>1 && checkEqual(l-1, l)) twos.erase(l-1);
            if(l>2 && checkEqual(l-2, l)) threes.erase(l-2);
            if(l>1 && l+1<=r && checkEqual(l-1, l+1)) threes.erase(l-1);

            if(r<n && checkEqual(r, r+1)) twos.erase(r);
            if(r<n-1 && checkEqual(r, r+2)) threes.erase(r);
            if(r<n && r-1>=l && checkEqual(r-1, r+1)) threes.erase(r-1);

            // debug(i);
            // debug(checkEqual(5, 7));
            // debug("Before update ", twos, threes);

            updateBIT(l, x);
            updateBIT(r+1, -x);

            // add conflicting threes and twos
            if(l>1 && checkEqual(l-1, l)) twos.insert(l-1);
            if(l>2 && checkEqual(l-2, l)) threes.insert(l-2);
            if(l>1 && l+1<=r && checkEqual(l-1, l+1)) threes.insert(l-1);

            if(r<n && checkEqual(r, r+1)) twos.insert(r);
            if(r<n-1 && checkEqual(r, r+2)) threes.insert(r);
            if(r<n && r-1>=l && checkEqual(r-1, r+1)) threes.insert(r-1);

            // debug("After update ", twos, threes);

        } else {
            int l, r;
            cin >> l >> r;
            // if twos or threes lies between [l, r]
            auto it = twos.lower_bound(l);
            if(it!=twos.end() && (*it)<=r-1) {
                cout << "NO\n";
                continue;
            }
            it = threes.lower_bound(l);
            if(it!=threes.end() && (*it)<=r-2) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
        }
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/