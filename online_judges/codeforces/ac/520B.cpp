// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "520B"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    if (n == m) cout << 0;
    else if (n < m){
        int cnt = 0;
        while (m > n){
            if (m & 1) m++, cnt++;
            else m /= 2, cnt++;
        }
        cout << cnt + (n - m);
    }
    else {
        cout << abs(m - n);
    }
    return 0;
}