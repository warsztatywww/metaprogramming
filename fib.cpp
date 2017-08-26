#include <iostream>
using namespace std;

template <int n>
struct fib {
    const static unsigned int value = fib<n-1>::value + fib<n-2>::value;
};

template <>
struct fib<0> {
    const static unsigned int value = 1;
};

template <>
struct fib<1> {
    const static unsigned int value = 1;
};

int main() {
    cout << fib<900>::value << endl;
}
