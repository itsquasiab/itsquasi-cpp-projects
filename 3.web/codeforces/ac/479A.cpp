//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll o1 = a + b + c;
    ll o2 = a * b * c;
    ll o3 = a + b * c;
    ll o4 = a * b + c;
    ll o5 = (a + b) * c;
    ll o6 = a * (b + c);
    cout << max({o1, o2, o3, o4, o5, o6});
    return 0;
}