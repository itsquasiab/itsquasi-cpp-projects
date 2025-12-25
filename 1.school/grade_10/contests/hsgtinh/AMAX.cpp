#include <bits/stdc++.h>
#define ll long long
#define tname "AMAX"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string a;
vector<string> f;

bool is_odd(char c){
    if (c == '1' || c == '3' || c == '5' || c == '7' || c == '9') return 1;
    return 0;
}

string remove_first_zero(string s){
    while (s.size() && s[0] == '0'){
        s.erase(0, 1);
    }
    return s;
}

string compare_number(string a, string b){
    if (a.size() > b.size()) return a;
    if (b.size() > a.size()) return b;
    for (int i = 0; i < a.size(); ++i){
        //cout << i << " ? " << a[i] << " : " << b[i] << "\n";
        if (a[i] > b[i]){
            //cout << a << " is bigger than " << b << " because " << a[i] << " > " << b[i] << " at position " << i << "\n";
            return a;
        }
        if (b[i] > a[i]){
            //cout << b << " is bigger than " << a << " because " << b[i] << " > " << a[i] << " at position " << i << "\n";
            return b;
        }
    }
    return a;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> a;
    a += 'a';
    string number = "", mxnumber = "";
    //ll mx = 0, num = 0;
    for (int j = 0; j < a.size(); ++j){
        if (a[j] >= '0' && a[j] <= '9'){
            number.push_back(a[j]);
            //num = num * 10 + (a[j] - '0');
        }
        else {
            if (!number.empty()){
                number = remove_first_zero(number);
                char last_digit = number[number.size() - 1];
                if (is_odd(last_digit)){
                    //cout << mxnumber << " " << number << "\n";
                    mxnumber = compare_number(mxnumber, number);
                }
            }
            number = "";
            /*if (num != 0 && num & 1){
                mx = max(mx, num);
            }
            num = 0;*/
        }
    }
    cout << mxnumber;
    return 0;
}
