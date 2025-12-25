//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll x, res = 0;
ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i]; 
    }
    sort(a + 1, a + 1 + n);
    int i = 1, j = n;
    while (i <= j){
        if (a[i] + a[j] <= x){
            res++;
            i++;
            j--;
        }
        else if (a[i] + a[j] > x){
            res++;
            j--;
        }
    }
    cout << res;
    return 0;
}