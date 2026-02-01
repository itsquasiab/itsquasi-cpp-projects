#include<iostream>

using namespace std;

//runtime error
string a;
int main(){
    getline(cin,a);
    string a1 = "";
    for (int i = 0; i <= a.length(); i++){
        if ((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
        a1 += a[i];
    }
    cout << a1;
    return 0;
}
