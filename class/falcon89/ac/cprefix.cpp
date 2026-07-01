// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define task "cprefix"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string a;

vector<ll> prefix_function(string s, int n){
    vector<ll> pi(n, 0);
    for (int i = 1; i < n; ++i){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
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
    cin >> a;
    int n = a.size();
    vector<ll> pi = prefix_function(a, n);
    vector<ll> cnt(n, 1);
    for (int i = n - 1; i > 0; --i){
        if (pi[i] > 0){
            cnt[pi[i] - 1] += cnt[i];
        }
        //cout << cnt[i] << " ";
    }
    for (int i = 0; i < n; ++i) cout << cnt[i] << " ";
    return 0;
}