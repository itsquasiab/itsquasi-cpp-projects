// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <iomanip>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

long double fspow(long double x, ll y){
    long double res = 1;
    while (y){
        if (y & 1){
            res *= x;
        }
        x *= x;
        y /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    long double a;
    int x;
    cin >> a >> x;
    cout << fixed << setprecision(2) << fspow(a, x);
    return 0;
}