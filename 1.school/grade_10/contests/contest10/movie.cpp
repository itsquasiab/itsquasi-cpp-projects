// Minding my own business. :)
// MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll m;
int n;

pair<ll, ll> a[arr];

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("movie.inp", "r"))
    {
        freopen("movie.inp", "r", stdin);
        freopen("movie.out", "w", stdout);
    }
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    int counter = 0;
    int i = 1;
    int remtime = 0;
    while (i <= n)
    {
        ll remaining_time = m;
        //cout << "watching movie " << i << "\n";
        while (remaining_time >= a[i].second)
        {
            ll episodes_today = remaining_time / a[i].second;
            remaining_time -= min(a[i].first, episodes_today) * a[i].second;
            //cout << "episodes watched today: " << episodes_today << "/" << a[i].first << "\n";
            if (episodes_today < a[i].first)
            {
                a[i].first -= episodes_today;
            }
            else if (episodes_today >= a[i].first)
            {
                a[i].first = 0;
                i++;
                //cout << "transition to " << i << " -> ";
            }
            //cout << i << " ";
            if (i > n){
                remtime = remaining_time;
                remaining_time = -1;
                break;
            }
        }
        counter++;
    }
    //cout << "\nres: ";
    cout << counter << " " << remtime;
    return 0;
}