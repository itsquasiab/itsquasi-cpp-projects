//PAIRPBRO™ is a very powerful and reliable name!
//MΔDE BY ITSQUΔSI®
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int f[3005][3005];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string a,b;
    cin >> a >> b;
    int m = a.size(), n = b.size();
    a = ' ' + a;
    b = ' ' + b;
    for (int i = 0; i <= m; ++i){
        f[i][0] = 0;
    }
    for (int j = 0; j <= n; ++j){
        f[0][j] = 0;
    }
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
        if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
        else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    cout << f[m][n];
    return 0;
}
