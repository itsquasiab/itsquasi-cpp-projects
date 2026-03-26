// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "twoopers"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll hs1[arr], pw[arr], ht[arr], n, n1;
string s, t, s1;

void build(){
    pw[0] = 1;
    for (int i = 1; i <= n1; ++i){
        hs1[i] = (hs1[i - 1] * base + (s1[i] - 'A' + 1)) % mod;
        pw[i] = (pw[i - 1] * base) % mod;
    }
    for (int i = 1; i <= n; ++i){
        ht[i] = (ht[i - 1] * base + (t[i] - 'A' + 1)) % mod;
    }
}

ll get(int i, int j){
    return (hs1[j] - hs1[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

ll get_t(int i, int j){
    return (ht[j] - ht[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> s >> t;
    s1 = s + s;
    n = s.size();
    n1 = s1.size();
    s = ' ' + s;
    s1 = ' ' + s1;
    t = ' ' + t;
    build();
    for (int i = 1; i <= n1; ++i){
        if (get(i, i + n - 1) == ht[n]){
            cout << n;
            return 0;
        }
    }
    /*for (int i = 1; i <= n; ++i){
        ll head1 = get(1, i - 1);
        ll tail1 = get(i + 1, n);
        ll head2 = get_t(1, i - 1);
        ll tail2 = get_t(i + 1, n);
        ll combine1 = (head1 * pw[n - i] % mod + tail1) % mod;
        ll combine2 = (head2 * pw[n - i] % mod + tail2) % mod;
        if (combine1 == combine2){
            
        }
    }*/
    return 0;
}