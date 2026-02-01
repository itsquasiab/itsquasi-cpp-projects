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
    int n;
    ll t;
    cin >> n >> t;
    ll time = 240 - t;
    int solved = 0, total = 0;
    while (total <= time && solved <= n){
        solved++;
        total += solved * 5;
    }
    cout << solved - 1;
    return 0;
}