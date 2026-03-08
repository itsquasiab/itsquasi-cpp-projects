// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <map>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

map<char, ll> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        char a;
        cin >> a;
        cnt[a]++;
    }
    char c = 0;
    ll s = 0;
    for (auto i : cnt){
        if (i.second > s){
            s = i.second;
            c = i.first;
        }
    }
    cout << c;
    return 0;
}