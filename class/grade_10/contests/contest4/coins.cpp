//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t, a, b;
    cin >> a >> b >> t;
    while (t--){
        ll n;
        cin >> n;
        ll cnt = -1, cnt1 = -1, cnt2 = -1;
        if (n % a == 0 || n % b == 0){
            if (n % a == 0) cnt1 = n / a;
            if (n % b == 0) cnt2 = n / b;
            cnt = min(cnt1, cnt2);
            if (cnt1 != -1) cnt = cnt1;
            if (cnt2 != -1) cnt = cnt2;
        }
        else {
            ll t1 = (n / max(a, b));
            ll t2 = n - (t1 * max(a, b));
            ll t3;
            if (t2 < min(a, b)) t3 = 1;
            else t3 = n / min(a, b);
            cnt = t1 + t3;
        }
        if (cnt & 1) cout << "A";
        else cout << "B";
    }
    return 0;
}