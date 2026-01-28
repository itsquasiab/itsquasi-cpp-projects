// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <stack>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string s;
int n;

int priority(char c){
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
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
    cin >> n;
    while (n--){
        cin >> s;
        stack<char> st;
        for (auto c : s){
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) cout << c;
            else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
                while (!st.empty() && priority(st.top()) >= priority(c)){
                    cout << st.top();
                    st.pop();
                }    
                st.push(c);
            }
            else if (c == '('){
                st.push(c);
            }
            else if (c == ')'){
                while (st.top() != '('){
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
        }
        while (!st.empty()){
            cout << st.top();
            st.pop();
        }
        cout << '\n';
    }
    return 0;
}