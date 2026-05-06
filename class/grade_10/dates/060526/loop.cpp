// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "loop"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ll> cap;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        cap.push_back(a);
    }
    int n2 = cap.size();
    for (int i = 0; i < n2; ++i){
        if (cap[i] % k == 0){
            for (int j = 0; j < k; ++j){
                cap.push_back(cap[i] / k);
                n2++;
            }
        }
        else break;
    }
    ll sum = 0;
    for (auto i : cap){
        sum += i;
    }
    cout << sum;
    return 0;
}