//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;
unsigned ll n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while (n != 1){
        cout << n << " ";
        if (n & 1) n = n * 3 + 1;
        else n /= 2;
    }
    cout << n;
    return 0;
}