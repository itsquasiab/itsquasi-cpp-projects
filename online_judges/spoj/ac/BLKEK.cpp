// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "BLKEK"

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
    int tsc;
    cin >> tsc;
    for (int c = 1; c <= tsc; ++c){
        string s;
        cin >> s;
        int num_k = 0, num_ke = 0, res = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == 'K'){
                if (num_ke != 0) res += num_ke;
                num_k++; 
            }
            else if (s[i] == 'E'){
                if (num_k != 0) num_ke += num_k;
            }
        }
        cout << res << "\n";
    }
    return 0;
}