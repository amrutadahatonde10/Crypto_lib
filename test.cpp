#include <iostream>
#include <NTL/ZZ.h>

int main() {
    NTL::ZZ a, b, c;
    a = 123456789;
    b = 987654321; 
    c = a * b;
    std::cout << "a * b = " << c << std::endl;
    return 0;
}