// Minding my own business. :)
// MADE BY ITSQUASI
#include <bits/stdc++.h>
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("closest.inp", "w", stdout);

    uniform_int_distribution<int> d_n(200000, 200000);
    uniform_int_distribution<int> d_a(100000, 1000000000);

    int n = d_n(rd);
    cout << n << "\n";
    for (int i = 1; i <= n; ++i){
        int a = d_a(rd);
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}
