#include <iostream>
using namespace std;

// x ? a : b
// if x: a else: b

template <int n>
struct fib {
    const static unsigned int value =
        (n == 0 ? 0 :
         (n == 1 ? 0 :
          fib<n-1>::value + fib<n-2>::value));
};

int main() {
    cout << fib<200>::value << endl;
}
