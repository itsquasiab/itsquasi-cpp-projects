// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "c11str2"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll ha[arr], hb[arr], pw[arr];
string a, b;
int m, n;

void make_hash(){
    pw[0] = 1;
    for (int i = 1; i <= max(m, n); ++i){
        pw[i] = (pw[i - 1] * base) % mod;
    }
    for (int i = 1; i <= n; ++i){
        ha[i] = (ha[i - 1] * base + (a[i] - 'a' + 1)) % mod;
    }
    for (int i = 1; i <= m; ++i){
        hb[i] = (hb[i - 1] * base + (b[i] - 'a' + 1)) % mod;
    }
}

ll get_hash1(int i, int j){
    return (ha[j] - ha[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

ll get_hash2(int i, int j){
    return (hb[j] - hb[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    make_hash();
    int i = n, j = 1;
    int sf1 = n + 1, sf2 = 0;
    while (i >= 1 && j <= m){
        //cout << i << " " << j << "\n";
        if (get_hash1(i, n) == get_hash2(1, j)){
            sf1 = i;
            sf2 = j;
        }
        i--;
        j++;
    }
    string prefix = a.substr(1, sf1 - 1);
    string suffix = b.substr(sf2 + 1, m - sf2);
    string middle = a.substr(sf1, n - sf1 + 1);
    cout << prefix << middle << suffix;
    return 0;
}