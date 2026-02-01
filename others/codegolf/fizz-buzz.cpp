#include <iostream>
#define c std::cout
int main(){for(int i=1;i<101;i++)(!(i%15)?c<<"FizzBuzz":!(i%3)?c<<"Fizz":!(i%5)?c<<"Buzz":c<<i)<<'\n';}