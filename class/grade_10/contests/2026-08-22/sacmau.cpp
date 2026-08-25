// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "sacmau"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

int a[arr];
int s1a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    //sub2
    unordered_map<int, int> s1;
    for (int i = 1; i <= n; ++i){
        s1[a[i]]++;
        if (s1[a[i]] == 1) s1a[i] = s1a[i - 1] + 1;
        else if (s1[a[i]] > 1) s1a[i] = s1a[i - 1] - 1;
    }
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        //sub2
        if (l == 1){
            cout << s1a[r] << "\n";
            continue;
        }
        //sub1
        unordered_map<int, int> cnt;
        for (int i = l; i <= r; ++i){
            cnt[a[i]]++;
        }
        int t = 0;
        for (auto i : cnt){
            if (i.second == 1) t++;
        }
        cout << t << "\n";
    }
    return 0;
}