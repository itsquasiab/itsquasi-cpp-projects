//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string a;
    cin >> a;
    ll mx = 0, cnt = 0;
    char ch = a[0];
    for (int i = 0; i < a.size(); ++i){
        if (a[i] == ch){
            cnt++;
        }
        else {
            ch = a[i];
            mx = max(mx, cnt);
            cnt = 1;
        }
    }
    mx = max(mx, cnt);
    cout << mx;
    return 0;
}