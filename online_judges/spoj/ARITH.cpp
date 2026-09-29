// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "ARITH"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        string a;
        cin >> a;
        string num1, num2;
        char op;
        int pos = -1;
        for (int i = 0; i < a.size(); ++i){
            if (!isdigit(a[i])){
                pos = i;
                op = a[i];
                num1 = num2;
                num2 = "";
            }
            else num2 += a[i];
        }
        if (pos == -1 || pos == 0 || pos == a.size() - 1) continue;
        ll n1 = stoll(num1);
        ll n2 = stoll(num2);
        if (op == '+' || op == '-'){
            ll n3 = 0;
            if (op == '+') n3 = n1 + n2;
            else n3 = n1 - n2;
            string num3 = to_string(n3);
            ll mxsz = max({num1.size(), num2.size() + 1, num3.size()});
            for (int i = 1; i <= mxsz - num1.size(); ++i) cout << " ";
            cout << num1 << "\n";
            for (int i = 1; i < mxsz - num2.size(); ++i) cout << " ";
            cout << op << num2 << "\n";
            for (int i = 1; i <= mxsz; ++i) cout << "-";
            cout << "\n";
            for (int i = 1; i <= mxsz - num3.size(); ++i) cout << " ";
            cout << num3 << "\n\n";
        }
        else {
            ll n3 = n1 * n2;
            string num3 = to_string(n3);
            ll mxsz_1 = max({num1.size(), num2.size() + 1, num3.size()});
            ll mxsz_2 = max(num1.size(), num2.size() + 1);
            for (int i = 1; i <= mxsz_1 - num1.size(); ++i) cout << " ";
            cout << num1 << "\n";
            for (int i = 1; i < mxsz_1 - num2.size(); ++i) cout << " ";
            cout << op << num2 << "\n";

            if (num2.size() > 1){
                for (int i = 1; i <= mxsz_1 - mxsz_2; ++i) cout << " ";
                for (int i = 1; i <= mxsz_2; ++i) cout << "-";
                cout << "\n";

                for (int i = num2.size() - 1; i >= 0; --i){
                    ll mn = (num2[i] - '0') * n1;
                    string mulnum = to_string(mn);
                    for (int j = 1; j <= mxsz_1 - mulnum.size() - (num2.size() - i - 1); ++j) cout << " ";
                    cout << mulnum << "\n";
                }
            }
            for (int i = 1; i <= mxsz_1; ++i) cout << "-";
            cout << "\n";
            for (int i = 1; i <= mxsz_1 - num3.size(); ++i) cout << " ";
            cout << num3 << "\n\n";
        }
    }
    return 0;
}