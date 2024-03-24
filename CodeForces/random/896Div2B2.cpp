/*

3
2 4 3

some power of 2 candies to some other person, 
no person can receive candies from more than one person
3 3 3

5
1 2 3 4 5


[1, 1e9]

6
1 4 7 1 5 4

7 5 1 1


6

10 7 4 3

1010 , 0111, 0100, 0011

0110

12
9 9 8 2 3 5 1 1 1 1

9 9 7 5 3 2 1 1 1 1



*/


/**
*   author: lazyhash(yashkundu)
*   created: 03 Feb, 2024 | 14:30:34
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
int a[N];
pair<int, int> ops[N];
 
void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    }

    if(sum%n) {
        cout << "NO\n";
        return;
    }

    int del = sum/n;

    for(int i=0;i<n;i++) {
        if(del==a[i]) continue;
        int x = abs(a[i]-del);
        int a = 1, b = 0;
        while(x%2==0) {
            a *= 2;
            x /= 2;
        }
        if(x!=1) {
            if(__builtin_popcount(x+1)!=1) {
                cout << "NO\n";
                return;
            }
            b = a*x;
        }
        // if(a[i]>del) ops[i] = {}
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