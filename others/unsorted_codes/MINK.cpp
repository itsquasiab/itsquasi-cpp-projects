// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <queue>
#define ll long long
#define task "MINK"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        deque<int> min_pos;
        for (int i = 1; i < k; ++i){
            while (!min_pos.empty() && a[min_pos.front()] > a[i]) min_pos.pop_front();
            min_pos.push_front(i);
        }
        for (int i = k; i <= n; ++i){
            if (!min_pos.empty() && min_pos.back() < i - k + 1) min_pos.pop_back();
            while (!min_pos.empty() && a[min_pos.front()] > a[i]) min_pos.pop_front();
            min_pos.push_front(i);
            cout << a[min_pos.back()] << " ";
        }
        cout << "\n";
    }
    return 0;
}