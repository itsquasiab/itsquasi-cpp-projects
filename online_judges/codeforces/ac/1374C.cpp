// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1374C"

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
        int n;
        string a;
        cin >> n >> a;
        ll opn = 0, res = 0;
        for (int i = 0; i < a.size(); ++i){
            if (a[i] == ')'){
                if (opn == 0) res++;
                else opn--;
            }
            else if (a[i] == '(') opn++;
        }
        cout << res << "\n";
    }
    return 0;
}