// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
#define task "550A"

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
    int n = a.size();
    a = " " + a;
    if (n <= 3){
        cout << "NO";
        return 0;
    }
    vector<pair<int, int>> ab, ba;
    for (int i = 2; i <= n; ++i){
        if (a[i - 1] == 'A' && a[i] == 'B') ab.push_back({i - 1, i});
        else if (a[i - 1] == 'B' && a[i] == 'A') ba.push_back({i - 1, i});
    }
    /*for (auto i : ab){
        cout << i.first << "-" << i.second << " ";
    }
    cout << "\n";
    for (auto i : ba){
        cout << i.first << "-" << i.second << " ";
    }*/
    if (ab.empty() || ba.empty()){
        cout << "NO";
        return 0;
    }
    int i = 0;
    while (i < ba.size()){
        //cout << ab[0].first << "-" << ab[0].second << " | " << ba[i].first << "-" << ba[i].second << "\n";
        if (ab[0].second >= ba[i].first){
            i++;
        }
        else if (ab[0].second < ba[i].first){
            cout << "YES";
            return 0;
        }
    }
    //cout << "\n";
    i = 0;
    while (i < ab.size()){
        //cout << ab[i].first << "-" << ab[i].second << " | " << ba[0].first << "-" << ba[0].second << "\n";
        if (ba[0].second >= ab[i].first){
            i++;
        }
        else if (ba[0].second < ab[i].first){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}