// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "cses1111"

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
        string hello = "hello";
        int j = 0;
        bool check = 0;
        for (int i = 0; i < a.size(); ++i){
            if (a[i] == hello[j]){
                j++;
            }
            if (j == hello.size()){
                check = 1;
                break;
            }
        }
        cout << (check ? "YES\n" : "NO\n");
    }
    return 0;
}