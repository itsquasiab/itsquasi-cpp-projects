// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "plane"

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
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    while (i < n && j < m){
        if (a[i] == b[j]){
            j++;
            i++;
            //cout << i << " " << j << "\n";
        }
        else i++;
    }
    if (j == m) cout << "YES";
    else cout << "NO";
    return 0;
}
