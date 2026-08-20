#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

mt19937_64 rd(chrono::high_resolution_clock().now()::time_since_epoch().count());
ll Rand(ll l, ll r) {
    return l + (unsigned long long)rd() % (r - l + 1);
}

const string a = "a", b = "b";

signed main() {
    int ntest = 100;
    while (ntest--) {
        ofstream inp((a + ".inp").c_str());
        //code
        inp.close();
        system((a + ".exe").c_str());
        system((b + ".exe").c_str());
        if (system(("fc " + a + ".out " + a + ".ans").c_str()) != 0) {
            cout << "RIP\n";
            return 0;
        }
        cout << "OK\n";
    }
}

