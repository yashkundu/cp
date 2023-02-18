/**
*    author:  lazyhash(yashkundu)
*    created: 12 Feb, 2023 | 08:29:34
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    int x = 1;
    while(x*(x+1)/2<n) x++;
    int sumA = 0;
    int Awhite = 0;
    for(int i=0;i<=x;i+=4) {
        sumA += i; Awhite += (i+1)/2;
    }
    for(int i=1;i<=x;i+=4) {
        sumA += i; Awhite += (i+1)/2;
    }

    if(x%4<2) {
        int excess = n - x*(x-1)/2;
        sumA += (n - (x*(x+1)/2));
        Awhite += (excess+1)/2 - (x+1)/2;
    }
   

    int sumB = n - sumA;

     int Ablack = sumA - Awhite;
    int Bwhite = (n+1)/2 - Awhite;
    int Bblack = sumB - Bwhite;

    cout << Awhite << " " << Ablack << " " << Bwhite << " " << Bblack << "\n";

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