//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 42, mod = 1e9, inf = LLONG_MIN;

ll n, x, t[arr], res;

vector<ll> a, b;

int calc (int m, int d){
    int s = 0;
    while (m > 0){
        s = s + (m & 1) * t[d - 1];
        d--;
        m >>= 1;
    }
    return s;
}

void make_ab(){
    // nửa đầu
    for (int m = 0; m < (1 << (n / 2)); ++m){
        a.push_back(calc(m, n / 2));
    }
    // nửa sau
    for (int m = 0; m < (1 << (n - n / 2)); ++m){
        b.push_back(calc(m, n - n / 2 + n / 2));
        // hoặc viết rõ: b.push_back(calc(m, n));
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; ++i){
        cin >> t[i];
    }

    make_ab();
    sort(b.begin(), b.end());

    for (ll v : a){
        ll need = x - v;
        // tìm số lượng phần tử bằng need trong b
        auto l = lower_bound(b.begin(), b.end(), need);
        auto r = upper_bound(b.begin(), b.end(), need);
        res += (r - l);
    }

    cout << res;
    return 0;
}