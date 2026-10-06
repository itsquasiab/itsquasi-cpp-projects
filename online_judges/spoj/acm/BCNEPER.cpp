// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "BCNEPER"

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
    int t;
    cin >> t;
    while (t--){
        int c;
        string os;
        cin >> c >> os;
        int i = os.size() - 2;
        while (i >= 0 && os[i] >= os[i + 1]) i--;
        if (i < 0){
            cout << c << " BIGGEST\n";
            continue;
        }
        int j = os.size() - 1;
        while (os[j] <= os[i]) j--;
        swap(os[i], os[j]);
        reverse(os.begin() + i + 1, os.end());
        cout << c << " " << os << "\n";
    }
    return 0;
}