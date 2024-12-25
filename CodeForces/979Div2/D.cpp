/**
*    author:  lazyhash(yashkundu)
*    created: 19 Oct, 2024 | 20:23:10
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

const int MAXN = (int)2e5+10;

int n, q;
int p[MAXN];

bool good[MAXN];

string s;
set<int> st;
 

int bad = 0;
int ind;


bool partition(int ind) {
    if(ind==n-1) return false;
    if(s[ind]=='L' && s[ind+1]=='R') return true;
    return false;
}



void update(int ind) {
    if(ind>0 && partition(ind-1) && !good[ind-1]) bad--;
    if(ind<n-1 && partition(ind) && !good[ind]) bad--;
    if(s[ind]=='L') s[ind]='R';
    else s[ind] = 'L';
    if(ind>0 && partition(ind-1) && !good[ind-1]) bad++;
    if(ind<n && partition(ind) && !good[ind]) bad++;
}


void solve() {
    cin >> n >> q;
    
    fill(good, good+n, 0);
    for(int i=0;i<n;i++) cin >> p[i];
    cin >> s;

    

    st.clear();

    int last = -1;
    for(int i=0;i<n;i++) {
        st.insert(p[i]);
        // debug(st, i, last);
        if(*st.rbegin()<=i+1 && st.size()==i-last) {
            good[i] = 1;
            st.clear();
            last = i;
        }
    }

    // debug(good[0], good[1], good[2], good[3], good[4]);

    bad = 0;
    for(int i=0;i<n-1;i++) {
        if(partition(i) && !good[i]) bad++;
    }

    // debug(bad);


    while(q--) {
        cin >> ind;
        ind--;
        update(ind);
        if(bad) cout << "NO\n";
        else cout << "YES\n";
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