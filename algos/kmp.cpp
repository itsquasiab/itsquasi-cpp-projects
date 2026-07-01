// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "kmp"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ll> prefix_function(string s){
    int n = s.size();
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
    string s;
    cin >> s;
    vector<ll> pi = prefix_function(s);
    for (auto i : pi){
        cout << i << " ";
    }
    return 0;
}