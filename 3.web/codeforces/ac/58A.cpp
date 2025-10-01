//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string a;
    cin >> a;
    string mask = "hello";
    int j = 0;
    bool f = 0;
    for (int i = 0; i < a.size(); ++i){
        if (a[i] == mask[j]) j++;
        if (j == mask.size()){
            f = 1;
            break;
        } 
    }
    if (f) cout << "YES";
    else cout << "NO";
    return 0;
}