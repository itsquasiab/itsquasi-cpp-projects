// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "131A"

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
    string a;
    cin >> a;
    int count_lower = 0;
    for (int i = 1; i < a.size(); ++i){
        if (islower(a[i])) count_lower++;
    }
    if (!count_lower){
        for (int i = 0; i < a.size(); ++i){
            if (isupper(a[i])) a[i] += 32;
            else a[i] -= 32;
        }
    }
    cout << a;
    return 0;
}