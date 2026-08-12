// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "489C"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool can(int m, int s){
    return s >= 0 && s <= 9 * m;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int m, s;
    cin >> m >> s;
    if (m == 1 && s == 0){
        cout << "0 0";
        return 0;
    }
    if ((m * 9 < s) || (s == 0 && m > 1)){
        cout << "-1 -1";
        return 0;
    }
    int sum1 = s, sum2 = s;
    string mn, mx;
    for (int i = 0; i < m; ++i){
        for (int d = 0; d < 10; ++d){
            if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum1 - d)){
                mn += char ('0' + d);
                sum1 -= d;
                break;
            }
        }
        for (int d = 9; d >= 0; --d){
            if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum2 - d)){
                mx += char ('0' + d);
                sum2 -= d;
                break;
            }
        }
    }
    cout << mn << " " << mx;
    return 0;
}