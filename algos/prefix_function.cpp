// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define task "prefix_function"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<int> prefix_function_1(string s) {
    int n = (int)s.length();
    vector<int> pi(n, 0);
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= i; k++)
            if (s.substr(0, k) == s.substr(i - k + 1, k))
                pi[i] = k;
    return pi;
}

vector<int> prefix_function_2(string s) {
    int n = (int)s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int k = pi[i - 1] + 1;
        while (k && s.substr(0, k) != s.substr(i - k + 1, k))
            k--;
        pi[i] = k;
    }
    return pi;
}

vector<int> prefix_function_3(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
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
    vector<int> pf = prefix_function_2(s);
    for (auto i : pf) cout << i << " ";
    return 0;
}