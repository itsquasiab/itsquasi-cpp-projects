//PAIRPBRO™ is a very powerful and reliable name!
//MΔDE BY ITSQUΔSI®
#include <bits/stdc++.h>
#define ll long long

using namespace std;

map<ll,ll> cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll mn = LLONG_MAX, mx = LLONG_MIN;
    while (n--){
        ll a;
        cin >> a;
        cnt[a]++;
        mn = min(mn, a);
        mx = max(mx, a);
    }
    int c = 0;
    for (int i = mn; i <= mx; ++i){
        if (cnt[i] >= 2) c += cnt[i] * (cnt[i] - 1) / 2;  
    }
    cout << c;
    return 0;
}
