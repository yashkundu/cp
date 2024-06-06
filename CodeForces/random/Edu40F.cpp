/**
*   author: lazyhash(yashkundu)
*   created: 07 Apr, 2024 | 21:50:39
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
#include <algorithm>
 
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

const int mod = 1e9+7;
using mi=mint<mod>;


vector<vector<mi>> mat1 = {
    {1, 1, 0},
    {1, 1, 1},
    {0, 1, 1}
};

vector<vector<mi>> mat2 = {
    {1, 1, 0},
    {1, 1, 0},
    {0, 0, 0}
};

vector<vector<mi>> mat3 = {
    {0, 0, 0},
    {0, 1, 1},
    {0, 1, 1}
};



vector<vector<mi>> mul(vector<vector<mi>> mat1, vector<vector<mi>> mat2) {
    int n1 = mat1.size(), n2 = mat1[0].size();
    int m1 = mat2.size(), m2 = mat2[0].size();

    assert(n2==m1);
    vector<vector<mi>> fMat(n1, vector<mi>(m2));
    for(int i=0;i<n1;i++) for(int j=0;j<m2;j++) {
        mi ans = 0;
        for(int k=0;k<n2;k++) ans += mat1[i][k]*mat2[k][j];
        fMat[i][j] = ans;
    }
    return fMat;
}


vector<vector<mi>> fastExp(vector<vector<mi>> mat, ll n) {
    vector<vector<mi>> res = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    while(n) {
        if(n&1) res = mul(res, mat);
        mat = mul(mat, mat);
        n = n >> 1;
    }
    return res;
}


 
void solve() {
    int n, m;
    cin >> n >> m;



    vector<pair<int, int>> events;


    for(int i=0;i<n;i++) {
        int a, l, r;
        cin >> a >> l >> r;
        events.push_back({l, a});
        events.push_back({r+1, -a});
    }

    events.push_back({1, 0});
    events.push_back({m+1, 0});

    sort(events.begin(), events.end());

    vector<int> obs = {0, 0, 0};


    vector<vector<mi>> ways = {{0, 1, 0}};


    int last = 0;
    for(int i=0;i<events.size() && events[i].first<m+1;i++) {
        int cur = events[i].first, nxt = events[i+1].first;
        if(events[i].second!=0) {
            int ind = abs(events[i].second)-1;
            if(events[i].second>0) obs[ind]++;
            else obs[ind]--;
        }
        
        if(last!=cur) {
            if(events[i].first==1) {
                ways = {{0, 1, 0}};
            } else {
                vector<vector<mi>> newWays = {{0, 0, 0}};
                newWays[0][0] = (obs[0]>0?0:(ways[0][0]+ways[0][1]));
                newWays[0][1] = (obs[1]>0?0:(ways[0][0]+ways[0][1]+ways[0][2]));
                newWays[0][2] = (obs[2]>0?0:(ways[0][1]+ways[0][2]));
                ways = newWays;
            }
            last = cur;
        }
        if(cur==nxt) continue;
        int del = nxt - cur - 1;
        if(del) {
            if(obs[1]>0) ;
            else if(obs[0]>0 && obs[2]>0) ;
            else if(obs[0]>0){
                vector<vector<mi>> mat = fastExp(mat3, del);
                ways = mul(ways, mat);
            } else if(obs[2]>0) {
                vector<vector<mi>> mat = fastExp(mat2, del);
                ways = mul(ways, mat);
            } else {
                vector<vector<mi>> mat = fastExp(mat1, del);
                ways = mul(ways, mat);
            }
        }
    }

    cout << ways[0][1].v << "\n";








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