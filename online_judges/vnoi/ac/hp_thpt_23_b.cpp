#include<iostream>

using namespace std;

//answer correct
string a;
int main(){
    getline(cin,a);
    int c = 0;
    for (int i = 0; i<=a.length(); i++){
        if (a[i]>='0'&&a[i]<='9') c++;
    }
    cout << c;
    return 0;
}
