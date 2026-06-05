// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

void func(int param = 0){
    cout << "parameter value: " << param << "\n";
}

string make_duplicates(string input, int &i){
    string make_duplicates = input + (i > 0 ? " (" + to_string(i) + ")" : "");
    i++;
    return make_duplicates;
}

int main()
{
    cout << "C++ PLAYGROUND by itsquasi\n\n";

    func(); // this will print 0 since it's a default value

    string name = "hello_world";
    int num_of_dups = 0;
    cout << make_duplicates(name, num_of_dups) << "\n";
    cout << make_duplicates(name, num_of_dups) << "\n";
    cout << make_duplicates(name, num_of_dups) << "\n";

    int num = 2;
    auto basic_lambda = [num](int x, int y){
        return (x + y) + num;
    };
    cout << basic_lambda(1, 2) << "\n";
    return 0;
}