// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1255"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll hsa[arr], pw[arr];

void make_hash(string a, int n){
    pw[0] = 1;
    for (int i = 1; i <= n; ++i){
        pw[i] = (pw[i - 1] * base) % mod;
        hsa[i] = (hsa[i - 1] * base + (a[i] - 'a' + 1)) % mod;
    }
}

ll get_hash(int i, int j){
    return (hsa[j] - hsa[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; ++cs){
        string a, b;
        cin >> a >> b;
        int n = a.size();
        int m = b.size();
        a = " " + a;
        b = " " + b;
        make_hash(a, n);
        ll hsb = 0;
        for (int i = 1; i <= m; ++i){
            hsb = (hsb * base + (b[i] - 'a' + 1)) % mod;
        }
        ll cases = 0;
        for (int i = 1; i <= n - m + 1; ++i){
            if (hsb == get_hash(i, i + m - 1)) cases++;
        }
        cout << "Case " << cs << ": " << cases << "\n";
    }
    return 0;
}