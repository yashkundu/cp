/**
*    author:  lazyhash(yashkundu)
*    created: 09 Jan,2023 | 10:26:12
**/
#include <iostream>
#include <vector>
#include <set>
#include <assert.h>
#include <iomanip>

using namespace std;


typedef long long ll;
typedef long double ld;

struct Vector{
    ld x, y;
    mutable ld len;
    Vector(ld x, ld y, ld len): x(x), y(y), len(len) {}
    bool operator<(const Vector &v) const {
        return x*v.y-y*v.x<0;
    }
};

ostream& operator<<(ostream &out,const Vector &v) {
    out << "< " << v.x << ", " << v.y << " > * " << v.len << " ,";
    return out;
}


struct Point{
    ld x, y;
    Point(ld x, ld y): x(x), y(y) {}
    Point operator+(const Point &p) const {
        return Point(x+p.x, y+p.y);
    }
    Point operator-(const Point &p) const {
        return Point(x-p.x, y-p.y);
    }
    Point operator+(const Vector &v) const {
        return Point(x+v.len*v.x, y+v.len*v.y);
    }
    Point operator-(const Vector &v) const {
        return Point(x-v.len*v.x, y-v.len*v.y);
    }
};

ostream& operator<<(ostream &out,const Point &p) {
    out << "( " << p.x << ", " << p.y << " ) ,";
    return out;
}

multiset<Vector> segs;

ostream& operator<<(ostream &out, const multiset<Vector> &segs) {
    out << "[ ";
    for(Vector v: segs) {
        out << v;
    }
    out << " ]\n";
    return out;
}


int n, a, b;
vector<int> p, q;

void solve() {
    
    cin >> n >> a >> b;
    p.resize(n);
    q.resize(n);
    segs.clear();

    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> q[i];

    // (a, b) ---   (0, b), (a, 0)
    Point first(0, b), last(a, 0);

    if(a>0) segs.insert(Vector(a, 0, 1));
    if(b>0) segs.insert(Vector(0, -b, 1));

    // cout << segs;

    for(int i=0;i<n;i++) {
        segs.insert(Vector(p[i], -q[i], 2));
        first = first - Point(p[i], -q[i]);
        last = last + Point(p[i], -q[i]);
        // cout << i << " ============== \n";
        // cout << first << last << "\n";
        // cout << segs;
        while(first.x<0) {
            assert(!segs.empty());
            auto it = segs.begin();
            if((first + *it).x<0) {
                first = first + *it;
                segs.erase(it);
                continue;
            }
            assert(it->x!=0);
            ld px = first.x, py = first.y;
            first.x = 0;
            first.y += (it->y)*(-px/it->x);
            it->len *= (1+px/(it->x*it->len));
        }

        while(last.y<0) {
            assert(!segs.empty());
            auto it = prev(segs.end());
            if((last - *it).y<0) {
                last = last - *it;
                segs.erase(it);
                continue;
            }
            assert(it->y!=0);
            ld px = last.x, py = last.y;
            last.y = 0;
            last.x -= (it->x)*(py/it->y);
            it->len *= (1 - (py/(it->y*it->len)));
        }
        // cout << " ~~~~~~~~~~~~~~~";
        // cout << first << last << "\n";
        // cout << segs;

        cout << setprecision(10) << last.x << "\n";
    }


}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

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