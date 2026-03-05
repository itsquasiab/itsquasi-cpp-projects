// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "how_rolling_hash_works"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

string a;
ll pow_a[arr], hash_a[arr], m, i, j;

void make_hash(){
    pow_a[0] = 1;
    hash_a[0] = 0;
    for (int i = 1; i <= m; ++i){
        pow_a[i] = (pow_a[i - 1] * base) % mod;
        hash_a[i] = (hash_a[i - 1] * base + (a[i] - '0' + 1)) % mod;
        cout << hash_a[i] << " ";
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
    cin >> a >> i >> j;
    cout << "\nlet's say you have a string: " << a << "\n";
    m = a.size();
    a = ' ' + a;
    cout << "and then you decided to hash it, which will give you these values: ";
    make_hash();
    cout << "\n";
    cout << "after that you want to get a hash at position: [" << i << ";" << j << "]\n";
    cout << "to do this, you get the hash at position " << j << ": " << hash_a[j] << "\n";
    cout << "then get the hash at position " << i - 1 << ": " << hash_a[i - 1];
    cout << ", multiply with the power at position " << j - i + 1 << ": " << pow_a[j - i + 1] << ", ";
    cout << "you will get " << hash_a[i - 1] * pow_a[j - i + 1] << "\n";
    cout << "then subtract the hash at position " << j;
    cout << " and the hash at position " << i - 1 << " multiply with power at position " << j - i + 1 << ", ";
    cout << "you will get the hash value: " << get_hash(i, j) << "\n\n";
    cout << "base: " << base << ", mod: " << mod << "\n";
    return 0;
}