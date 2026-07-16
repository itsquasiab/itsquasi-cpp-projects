// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define task "cau2b"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string s;
    cin >> s;
    vector<char> upc, lwc;
    for (char c : s){
        if (isupper(c)) upc.push_back(c);
        else lwc.push_back(c);
    }
    sort(upc.begin(), upc.end(), greater<ll>());
    sort(lwc.begin(), lwc.end(), greater<ll>());
    for (char c : upc) cout << c;
    for (char c : lwc) cout << c;
    return 0;
}