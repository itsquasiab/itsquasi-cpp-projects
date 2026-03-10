// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll d1[arr], d2[arr], d3[arr]; // d1:A->Z; d2: a->z; d3: 0->9

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    d1[1] = d2[1] = d3[1] = 0;
    for (int i = 1; i <= n; ++i){
        d1[i] = d1[i - 1];
        d2[i] = d2[i - 1];
        d3[i] = d3[i - 1];
        if (s[i] >= 'A' && s[i] <= 'Z') d1[i]++;
        else if (s[i] >= 'a' && s[i] <= 'z') d2[i]++;
        else if (s[i] >= '0' && s[i] <= '9') d3[i]++;
    }
    ll d = 0;
    int i = 0;
    for (int j = 1; j <= n; ++j){
        while (i + 6 <= j && d1[j] - d1[i] > 0 && d2[j] - d2[i] > 0 && d3[j] - d3[i] > 0){
            i++;
        }
        d += i;
    }
    cout << d;
    return 0;
}