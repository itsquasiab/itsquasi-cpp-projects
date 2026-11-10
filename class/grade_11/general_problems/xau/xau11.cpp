// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "xau11"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<int> letters[30];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string a;
    int k;
    cin >> a >> k;
    a = ' ' + a;
    for (int i = 0; i < 26; ++i){
        letters[i].assign(a.size() + 1, 0);
    }
    for (int i = 1; i < a.size(); ++i){
        for (int j = 0; j < 26; ++j) letters[j][i] = letters[j][i - 1];
        int current_letter = a[i] - 'a';
        letters[current_letter][i]++;
    }
    while (k--){
        int l, r;
        cin >> l >> r;
        int cnt_odds = 0;
        for (int i = 0; i < 26; ++i){
            int cnt = letters[i][r] - letters[i][l - 1];
            cnt_odds += (cnt & 1);
        }
        if (cnt_odds > 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}