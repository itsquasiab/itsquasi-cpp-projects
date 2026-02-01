//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <algorithm>
#define ll long long
#define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
pair<ll, int> a[arr];
ll x;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /*if (fopen(task".inp","r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }*/
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        ll target = x - a[i].first;
        int l = i + 1, r = n;
        while (l < r){
            if (a[l].first + a[r].first == target){
                cout << a[i].second << " " << a[l].second << " " << a[r].second;
                return 0;
            }
            else if (a[l].first + a[r].first > target){
                r--;
            }
            else l++;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}