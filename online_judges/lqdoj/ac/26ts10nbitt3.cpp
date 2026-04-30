// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "26ts10nbitt3"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll c = 0, a = 0, r = 0;

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
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i){
        if (s[i] == 'C') c++;
        else if (s[i] == 'A') a += c;
        else if (s[i] == 'R') r += a;
    }
    cout << r;
    return 0;
}