// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "latgach"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string dp[106];

string add(string a, string b){
    while (a.size() < b.size()) a = '0' + a;
    while (b.size() < a.size()) b = '0' + b;
    string res;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i){
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res = char(sum % 10 + '0') + res;
        carry = sum / 10;
    }
    if (carry) res = '1' + res;
    return res;
}

void sieve(){
    dp[1] = "1";
    dp[2] = "2";
    for (int i = 3; i <= 100; ++i){
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    sieve();
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
