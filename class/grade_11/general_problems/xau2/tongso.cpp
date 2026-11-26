// Minding my own business. :)
// MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define task "tongso"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string add(string a, string b){
    string res;
    if (a.size() > b.size()) swap(a, b);
    while (a.size() < b.size()){
        a = '0' + a;
    }
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i){
        int total = (a[i] - '0') + (b[i] - '0') + carry;
        int appending = (total % 10);
        res = to_string(appending) + res;
        carry = total / 10;
    }
    if (carry > 0) {
        res = char(carry + '0') + res;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string s;
    cin >> s;
    s += " ";
    string num, res;
    for (auto c : s){
        if (isdigit(c)){
            num += c;
        }
        else if (num != ""){
            res = add(res, num);
            num = "";
        }
    }
    for (int i = 0; i < res.size(); ++i){
        if (res[i] == '0'){
            res.erase(i, 1);
            i--;
        }
        else break;
    }
    cout << res;
    return 0;
}