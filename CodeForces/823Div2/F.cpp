/**
*    author:  lazyhash(yashkundu)
*    created: 08 Jan,2023 | 01:35:53
**/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

template<typename T>
struct bit{
    int n;
    vector<T> v;
    bit(int n): n(n) {v.resize(n+1);}
    void add(int ind, T val) {
        ind++; for(;ind<=n;ind+=ind&(-ind)) v[ind] += val;
    }
    T get(int ind) {
        ind++; T ans = T(); 
        for(;ind>0;ind-=ind&(-ind)) ans += v[ind]; return ans; 
    }
    T get(int l, int r) {
        return get(r) - get(l-1);
    }
    T lower_bound(T x) {
        int ind = 0, sum = T();
        for(int pw=1<<25;pw>0;pw>>=1) if(ind+pw<=n && sum + v[ind+pw]<x) ind = ind +  pw, sum += v[ind+pw];
        return ind;
    }
};

int n, k;
vector<int> p, pos;
bit<int> t(0);

int inv(int mn, int msk, int x) {
    int ans = 0;
    for(int i=0;i<k;i++) {
        if((msk & (1<<i))!=0 && pos[mn+i+1]>pos[x]) ans++;
    }
    ans += t.get(pos[x]+1, n-1);
    return ans;
}

void solve() {
    cin >> n >> k;
    p.resize(n);
    pos.resize(n);
    t = bit<int>(n);

    for(int i=0;i<n;i++) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }

    // q
    // 4 1 3 5 2 7 12 23 
    // used   |mn| maybe used or unused  |mn+k| unused
    // dp[mn][mask] -- min number of inversions

    vector<vector<int>> dp(n+1, vector<int>(1<<k, 1e9));
    
    // // 0 1 2 3 4 5 6 7 8 9
    dp[0][0] = 0;
    for(int mn=0;mn<n;mn++) {
        for(int msk=0;msk<(1<<min(k, n-mn-1));msk++) {
            for(int j=0;j<min(k, n-mn-1);j++) {
                if((msk&(1<<j))==0) {
                    dp[mn][msk + (1<<j)] = min(dp[mn][msk + (1<<j)], dp[mn][msk] + inv(mn, msk, mn+1+j));
                }
            }
            int mn2 = mn, msk2 = msk;
            mn2++;
            while(msk2%2) {
                mn2++;
                msk2 /= 2;
            }
            msk2 /= 2;
            dp[mn2][msk2] = min(dp[mn2][msk2], dp[mn][msk] + inv(mn, msk, mn));
        }  
        t.add(pos[mn], 1);
    }

    cout << dp[n][0] << "\n";

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/