//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

int n;
ll a[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j < i; ++j){
            if (a[i][j] != 0){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}