// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define task "bai2"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string upper = "";

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    string a;
    cin >> n >> a;
    ll tmp = 0, num = 0;
    bool isnum = 0;
    for (int i = 0; i < n; ++i){
        if (isupper(a[i])) upper += a[i];
        if (isdigit(a[i])){
            tmp = tmp * 10 + (a[i] - '0');
            isnum = 1;
        }
        else {
            num += tmp;
            tmp = 0;
        }
    }
    num += tmp;
    cout << upper;
    if (isnum) cout << num;
    return 0;
}