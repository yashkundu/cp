    /**
    *    author:  lazyhash(yashkundu)
    *    created: 30 Nov, 2024 | 20:11:17
    **/
    #include <iostream>
    #include <vector>
    #include <random>
    #include <chrono>
    
    using namespace std;
    
    typedef long long ll;
    typedef long double ld;
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int n, m, k;
    string s;
    
    void solve() {
        cin >> n >> m >> k;
        cin >> s;

        int valid = -1;
        int cnt0 = 0;
        int ans = 0;

        for(int i=0;i<n;i++) {
            if(i<=valid) {
                cnt0 = 0;
                continue;
            }
            if(s[i]=='1') cnt0 = 0;
            else cnt0++;
            if(cnt0==m) {
                cnt0 = 0;
                valid = i+k-1;
                ans++;
            }
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
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * - BenQ
    */