// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "divseq"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

vector<ll> prefix_function(int n, ll a[]){
    vector<ll> pi(n, 0);
    for (int i = 1; i < n; ++i){
        int j = pi[i - 1];
        while (j > 0 && a[i] != a[j]) j = pi[j - 1];
        if (a[i] == a[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    ll res = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> pi = prefix_function(n, a);
    ll l = n - pi[n - 1];
    cout << l;
    return 0;
}