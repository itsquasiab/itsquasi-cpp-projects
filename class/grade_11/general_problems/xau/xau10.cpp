// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "xau10"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

unordered_map<char, int> mp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    //unfinished project
    string a;
    int k;
    cin >> a >> k;
    int i = 0, j = 0, res = 0, bit0 = 0, bit1 = 0;
    while (i < a.size() && j < a.size()){
        if (a[j] == '0') bit0++;
        else bit1++;
        while (abs(bit0 - bit1) > 1){
            if (a[i] == '0') bit0--;
            else bit1--;
            i++;
        }
        cout << j - i + 1 << "\n";
        res = max(res, j - i + 1);
        j++;
    }
    cout << res + k;
    return 0;
}