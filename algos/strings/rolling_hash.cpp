// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "rolling_hash"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

string a, b;
ll pow_a[arr], hash_a[arr], hash_b;
int m, n;

void make_hash(){
    pow_a[0] = 1;
    for (int i = 1; i <= m; ++i){
        pow_a[i] = (pow_a[i - 1] * base) % mod;
        hash_a[i] = (hash_a[i - 1] * base + (a[i] - '0' + 1)) % mod;
    }
    for (int i = 1; i <= n; ++i){
        hash_b = (hash_b * base + (b[i] - '0' + 1)) % mod;
    }
}

ll get_hash(int i, int j){
    return (hash_a[j] - hash_a[i - 1] * pow_a[j - i + 1] + mod * mod) % mod;
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
    m = a.size();
    n = b.size();
    a = ' ' + a;
    b = ' ' + b;
    make_hash();
    for (int j = n; j <= m; ++j){
        int i = j - n + 1;
        if (get_hash(i, j) == hash_b) cout << i << " ";
    }
    return 0;
}