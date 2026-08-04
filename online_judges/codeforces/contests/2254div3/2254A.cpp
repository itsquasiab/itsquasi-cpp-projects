// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "2254A"

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
        ll a, b, c;
        cin >> a >> b >> c;
        int round = 0;
        while (a != c && b != c && a != b){
            ll mxtoken = max({a, b, c});
            ll mntoken = min({a, b, c});
            if (a == mxtoken) a--;
            else if (b == mxtoken) b--;
            else c--;
            if (a == mntoken) a++;
            else if (b == mntoken) b++;
            else c++;
            round++;
            //cout << a << " " << b << " " << c << "\n";
        }
        cout << round << "\n";
    }
    return 0;
}