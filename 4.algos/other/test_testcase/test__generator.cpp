//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int example = 1 + rd() % 10;
int n = 3;
int m = 1 + rd() % 100;
ll a = ((rd() % 100) + 1) * 100;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << n << " " << m << "\n";
    for (int i = 1; i <= n; ++i){
        cout << ((rd() % 100) + 1) * 100 << " ";
    }
    return 0;
}