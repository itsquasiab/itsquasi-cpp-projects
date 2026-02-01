//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n;
vector<ll> a;

void radix_sort() {
    ll mx = *max_element(a.begin(), a.end());

    // exp = 1, 10, 100, ...
    for (int exp = 1; mx / exp > 0; exp *= 10) {
        vector<ll> cnt(10, 0);
        vector<ll> output(n);

        // Count digits
        for (int i = 0; i < n; i++)
            cnt[(a[i] / exp) % 10]++;

        // Prefix sum (stable position)
        for (int i = 1; i < 10; i++)
            cnt[i] += cnt[i - 1];

        // Build output (right → left to keep stability)
        for (int i = n - 1; i >= 0; i--) {
            int digit = (a[i] / exp) % 10;
            output[--cnt[digit]] = a[i];
        }

        //Copy back
        a = output;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        ll x;
        cin >> x;
        a.push_back(x);
    }
    radix_sort();
    for (auto i : a){
        cout << i << " ";
    }
    return 0;
}