// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "EXCEL"

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
    while (true){
        string a;
        cin >> a;
        if (a == "R0C0") break;
        ll row = 0, col = 0;
        for (int i = 1; i < a.size(); ++i){
            if (a[i] == 'C') row = col, col = 0;
            else col = col * 10 + (a[i] - '0');
        }
        //cout << row << " " << col << "\n";
        string text = "";
        while (col){
            col--;
            ll rem = col % 26;
            char ch = (rem + 'A');
            text = ch + text;
            col /= 26;
        }
        cout << text << row << "\n";
    }
    return 0;
}