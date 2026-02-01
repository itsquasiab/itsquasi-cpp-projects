//PAIRPBRO™ is a very powerful and reliable name!
//MΔDE BY ITSQUΔSI®
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[1000006];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    ll sumn = abs(a[2] - a[1]);
    for (int i = 2; i < n; ++i){
        sumn = min(sumn, abs(a[i + 1] - a[i]));
    }
    cout << sumn;
    return 0;
}
