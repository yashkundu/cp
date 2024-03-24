/**
*   author: lazyhash(yashkundu)
*   created: 29 Dec, 2023 | 15:51:08
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set __gnu_pbds::tree<int, __gnu_pbds::null_type,less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> 
 
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

template<int MOD> struct mint {
    static const int mod = MOD;
    int v;
    explicit operator int() const {return v;}
    mint(): v(0) {}
    mint(ll _v) {
        v = int((_v > -MOD && _v < MOD)?_v:_v%MOD);
        if(v<0) v += MOD;
    }
    bool operator==(const mint& o) const{ return (v==o.v);}
    friend bool operator!=(const mint& a, const mint& b) {return !(a==b);}
    friend bool operator<(const mint& a, const mint& b) {return a.v<b.v;}
    friend bool operator>(const mint& a, const mint& b) {return a.v>b.v;}
    friend bool operator<=(const mint& a, const mint& b) {return a.v<=b.v;}
    friend bool operator>=(const mint& a, const mint& b) {return a.v>=b.v;}

    friend mint operator+(mint a, const mint& b) {return a += b;}
    friend mint operator-(mint a, const mint& b) {return a -= b;}
    friend mint operator*(mint a, const mint& b) {return a *= b;}
    friend mint operator/(mint a, const mint& b) {return a /= b;}

    mint& operator+=(const mint& o) {if((v+=o.v)>=MOD) v -= MOD; return *this;}
    mint& operator-=(const mint& o) {if((v-=o.v)<0) v += MOD; return *this;}
    mint& operator*=(const mint& o) {v = int((ll)v*o.v%MOD); return *this;}
    mint& operator/=(const mint& o) {return (*this) *= inv(o);}

    friend mint pow(mint a, ll n) {
        mint res = 1; assert(n>=0);
        for(;n;n/=2, a*=a) if(n&1) res *= a;
        return res;
    }
    friend mint inv(mint a) {return pow(a, MOD-2);}

    mint operator-() {return mint(-v);}
    mint& operator++() {return *this += 1;}
    mint& operator--() {return *this -= 1;}

    friend istream& operator>>(istream& in, const mint& o) {
        ll x; in >> x; o.v = int(mint(x)); return in;
    }
    friend ostream& operator<<(ostream& out, const mint& o) {
        out << o.v; return out;
    }
};

const int mod = 998244353;

using mi=mint<mod>;

 
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n), q(k);
    for(int &x: p) cin >> x;
    for(int &x: q) cin >> x;

    ordered_set st;


    mi qInvCnt = 0;
    for(int i=k-1;i>=0;i--) {
        qInvCnt += st.order_of_key(q[i]);
        st.insert(q[i]);
    }

    mi ans = qInvCnt*n;
    st.clear();

    // now procedding for different pair of elements in p


    auto num_elements_in_range = [&st](int l, int r) { 
        // (l, r]
        return st.order_of_key(r) - st.order_of_key(l);
    }; 

    for(int i=n-1;i>=0;i--) {
        // p[i]
        // iterating over els < p[i]
        int x = p[i];
        int del = 0;
        while(x>1) {
            // ((x+1)/2, x]
            mi coeff = mi(k)*(k+1)/2 + mi(k)*del - mi(del)*(del+1)/2;
            if(del>=k-1) coeff = mi(k)*k;
            ans += coeff*num_elements_in_range((x+1)/2, x);
            x = (x+1)/2;
            del++;
            // if(x==2) {
            //     coeff = mi(k)*(k+1)/2 + mi(k)*del - mi(del)*(del+1)/2;
            //     ans += coeff*num_elements_in_range(1, 2);
            // }
        }

        x = p[i];
        del = 1;
        while(x<2*n) {
            // (x, 2x]
            // x = 2x
            mi coeff = mi(k)*(k+1)/2 - mi(k)*del + mi(del)*(del-1)/2;
            if(del>=k) coeff = 0;
            ans += coeff*num_elements_in_range(x, 2*x);
            x = 2*x;
            del++;
        }

        // 
        st.insert(p[i]);
    }

    cout << ans.v << "\n";


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