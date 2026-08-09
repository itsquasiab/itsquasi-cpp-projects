// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "897B"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

/*bool check(ll x){
    string s = to_string(x);
    if (s.size() & 1) return 0;
    for (int i = 0; i < s.size() / 2; ++i){
        if (s[i] != s[s.size() - i - 1]) return 0;
    }
    return 1;
}*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int k;
    ll p;
    cin >> k >> p;
    ll i = 1, sum = 0;
    while (k){
        string s = to_string(i);
        string rev = s;
        reverse(rev.begin(), rev.end());
        s = s + rev;
        ll num = stoll(s);
        //cout << num << " ";
        sum = (sum + num) % p;
        k--;
        i++;
    }
    cout << sum;
    return 0;
}