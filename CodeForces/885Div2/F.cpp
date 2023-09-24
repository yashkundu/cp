/**
*   author: lazyhash(yashkundu)
*   created: 30 Jul, 2023 | 22:51:54
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> a;

// after every n ops arrays length will be halved so tComplexity : n + n/2 + n/4 + n/8 ~ 2n ~ O(n)
int solve(int n) {
    //  1, 2
    if(n==1) {
        if(a[0]==0) return 0;
        return 1;
    }
    if(n==2) {
        if(a[0]==a[1]) {
            if(a[0]==0) return 0;
            return 1;
        }
        return 2;
    }
    // Lets check if n/2 ops makes the array zero.
    // for every element check if a[i]=a[(i+n/2)modn]
    bool isValid = true;
    for(int i=0;i<n;i++) {
        if(a[i]!=a[(i+n/2)%n]) isValid = false;
    }

    // if isValid = true, that means we just have to found the no. of operations for prefix of size n/2 and double them, because a[i]==a[(i+n/2)modn] already, ex: 2, 1, 3, 2, 1, 3
    if(isValid) 
        return solve(n/2);

    // if isValid = false, means, we have to perform atleast n/2 operations, after n/2 operations, a[i] w= a[(i+n/2)modn] because after n operations array will become zero, ex: 2, 1, 3, 2, 1, 3
    // perform n/2 operations
    vector<int> tmp(a.begin(), a.begin()+n);
    for(int i=0;i<n;i++) a[i] = tmp[i] ^ tmp[(i+n/2)%n];
    return n/2 + solve(n/2);
}

 
void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for(int &x: a) cin >> x;


    // after evert 2^t operations every element would be xored by the elemente with a distance of 2^t to the right
    // a0           -       0
    // a0a1         -       1
    // a0a2         -       2
    // a0a1a2a3     -       3
    // a0a4 `       -       4
    // the ans can be atmost n, because it is 2^k, after n operations all elems will be xored by same elems.
    // If the array becomes zero, all subsequent operations will not change the array.


    cout << solve(n) << "\n";

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