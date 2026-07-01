// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <set>
#define ll long long
#define task "xnp"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll n;
    cin >> n;
    string bit = "";
    while (n > 0){
        bool t = n % 2;
        bit = to_string(t) + bit;
        n /= 2;
    }
    //cout << bit;
    int len = bit.size();
    set<ll> nums;
    for (int i = 0; i < len; ++i){
        for (int j = 1; j <= len - i; ++j){
            string subbit = bit.substr(i, j);
            //cout << i << " " << j << "\n";
            //cout << subbit << "\n";
            ll num = stoll(subbit, nullptr, 2);
            nums.insert(num);
        }
    }
    ll sum = 0;
    for (auto i : nums){
        sum += i;
    }
    cout << sum;
    return 0;
}