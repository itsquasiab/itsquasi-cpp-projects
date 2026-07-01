//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e3 + 6, MOD = 1e9 + 9;

ll l[ARR][ARR];
pair<ll,ll> a[ARR];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= w; ++j){
            if (a[i].first <= j){
                l[i][j] = max(l[i - 1][j - a[i].first] + a[i].second, l[i - 1][j]);
            }
            else{
                l[i][j] = l[i - 1][j];
            }
        }
    }
    cout << l[n][w] << " ";
    vector<ll> ch;
    int i = n, j = w;
    while (i > 0 && j > 0) {
        if (l[i][j] != l[i - 1][j]) {
            ch.push_back(i);
            j -= a[i].first;
        }
        --i;
    }
    cout << ch.size() << "\n";
    for (int i = ch.size() - 1; i >= 0; --i){
        cout << ch[i] << "\n";
    }
    return 0;
}