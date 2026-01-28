// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string s;
int n;

ll fastpow(ll x, ll y){
    ll res = 1;
    while (y){
        if (y & 1) res *= x;
        x *= x;
        y /= 2;
    }
    return res;
}

int priority(char c){
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

ll apply(ll a, ll b, char op){
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return fastpow(a, b);
    return 0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> s;
    stack<char> st;
    stack<ll> calc;
    vector<string> postfix;
    for (int i = 0; i < s.size(); ++i){
        if (isdigit(s[i])){
            string num;
            while (i < s.size() && isdigit(s[i])){
                num += s[i];
                i++;
            }
            i--;
            postfix.push_back(num);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
            while (!st.empty() && priority(st.top()) >= priority(s[i])){
                postfix.push_back(string(1, st.top()));
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            while (st.top() != '('){
                postfix.push_back(string(1, st.top()));
                st.pop();
            }
            st.pop();
        }
    }
    while (!st.empty()){
        postfix.push_back(string(1, st.top()));
        st.pop();
    }
    cout << "reverse polish notation: ";
    for (auto i : postfix){
        cout << i << " ";
    }
    cout << "\n";
    for (auto c : postfix){
        if (isdigit(c[0])){
            calc.push(stoll(c));
        } else {
            ll b = calc.top(); calc.pop();
            ll a = calc.top(); calc.pop();
            calc.push(apply(a, b, c[0]));
        }
    }
    cout << "result: " << calc.top() << "\n";
    return 0;
}