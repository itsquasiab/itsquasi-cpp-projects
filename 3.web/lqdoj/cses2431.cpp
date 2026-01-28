// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
unsigned ll k;
unsigned ll pw[19];

void pre(){
    pw[0] = 1;
    pw[1] = 10;
    for (int i = 2; i <= 18; ++i){
        pw[i] = pw[i - 1] * 10;
    }
}

unsigned ll td(ll x){
    //if (x >= 18) return 2e18;
    return (9 * pw[x - 1]) * x;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    pre();
    cin >> n;
    while (n--){
        cin >> k;
        int d1 = 1;
        for (int d = 1; d <= 18; ++d){
            //cout << k << " " << td(d) << "\n";
            if (k > td(d)){
                k -= td(d);
            }
            else {
                d1 = d;
                break;
            }
        }
        int idx = (k - 1) / d1;
        int pos = (k - 1) % d1;
        unsigned ll stt = pw[d1 - 1];
        unsigned ll num = stt + idx;
        string res = to_string(num);
        cout << res[pos] << "\n";
    }
    return 0;
}