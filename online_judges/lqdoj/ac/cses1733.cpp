// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "cses1733"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll ha[arr], pw[arr];
string a;
int n;

void make_hash(){
    ha[0] = 0;
    pw[0] = 1;
    for (int i = 1; i <= n; ++i){
        ha[i] = (ha[i - 1] * base + (a[i] - 'a' + 1)) % mod;
        pw[i] = (pw[i - 1] * base) % mod;
    }
}

ll get_hash(int i, int j){
    return (ha[j] - ha[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> a;
    n = a.size();
    a = ' ' + a;
    make_hash();
    for (int i = 1; i <= n; ++i){
        ll h1 = get_hash(1, i);
        bool overlap = 1;
        for (int j = i + 1; j <= n; j += i){
            //cout << j << " " << min(n, j + i - 1) << "\n";
            ll h2 = get_hash(j, min(n, j + i - 1));
            if (j + i > n){
                ll cut = n - j + 1;
                ll h1a = get_hash(1, cut);
                //cout << "-> " << 1 << " " << cut << "\n";
                if (h1a != h2){
                    overlap = 0;
                    break;
                }
            }
            else if (h1 != h2){
                overlap = 0;
                break;
            }
        }
        //cout << "overlap: " << overlap << " at " << i << "\n";
        if (overlap == 1) cout << i << " ";
    }
    return 0;
}
