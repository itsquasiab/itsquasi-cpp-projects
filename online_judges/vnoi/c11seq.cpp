//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], pref[arr], bit[arr];

unordered_map<ll, bool> exist;
vector<ll> com;

void update(int p, int n){
    for (int i = p; i <= n; i += i & -i){
        bit[i]++;
    }
}

ll get(int p){
    ll sum = 0;
    for (int i = p; i >= 1; i -= i & -i){
        sum += bit[i];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    ll l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        if (!exist[pref[i]]){
            com.push_back(pref[i]);
            exist[pref[i]] = 1;
        }
    }
    sort(com.begin(), com.end());
    for (int i = 1; i <= n; ++i){
        pref[i] = lower_bound(com.begin(), com.end(), pref[i]) - com.begin() + 1;
    }
    int m = com.size();
    //update(pref[0], m);
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        ll s = com[pref[i] - 1];
        ll lv = s - r + 1;
        ll rv = s - l - 1;
        int li = lower_bound(com.begin(), com.end(), lv) - com.begin() + 1;
        int ri = upper_bound(com.begin(), com.end(), rv) - com.begin();
        if (li <= ri && li >= 1 && ri <= m){
            res += get(ri) - get(li - 1);
        }
        update(pref[i], m);
    }
    cout << res;
    return 0;
}