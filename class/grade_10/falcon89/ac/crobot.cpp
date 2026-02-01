//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll s, a, b, x;
    cin >> s >> a >> b >> x;
    ll distance_per_wave = s * a;
    ll time_per_wave = a + b;
    ll wave = x / time_per_wave;
    ll additional_wave = x % time_per_wave;
    ll additional_distance = min(additional_wave, a);
    ll total_distance = distance_per_wave * wave + additional_distance * s;
    cout << total_distance;
    return 0;
}