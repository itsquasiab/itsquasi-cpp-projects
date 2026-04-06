// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "primefactors"

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
    ll n;
    cin >> n;
    string exp = "";
    for (int i = 2; i * i <= n; ++i){
        while (n % i == 0){
            n /= i;
            exp += to_string(i) + "*";
        }
    }
    if (n > 1) exp += to_string(n);
    if (exp[exp.size() - 1] == '*') exp.erase(exp.size() - 1);
    cout << exp;
    return 0;
}