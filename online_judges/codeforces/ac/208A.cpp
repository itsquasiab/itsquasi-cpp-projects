// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <sstream>
#define ll long long
#define task "208A"

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
    string a;
    cin >> a;
    for (int i = 2; i < a.size(); ++i){
        if (a[i - 2] == 'W' && a[i - 1] == 'U' && a[i] == 'B'){
            a[i - 2] = a[i - 1] = a[i] = ' ';
        }
    }
    stringstream ss(a);
    string word;
    while (ss >> word){
        cout << word << " ";
    }
    return 0;
}