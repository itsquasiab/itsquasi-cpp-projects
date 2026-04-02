// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "cau2b"

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
    int n;
    cin >> n;
    while (n--){
        string a;
        cin >> a;
        bool up = 0, lw = 0, nm = 0, sc = 0;
        for (char c : a){
            if (isupper(c)) up = 1;
            else if (islower(c)) lw = 1;
            else if (isdigit(c)) nm = 1;
            else sc = 1;
        }
        cout << ((up && lw && nm && sc) ? "YES\n" : "NO\n");
    }
    return 0;
}