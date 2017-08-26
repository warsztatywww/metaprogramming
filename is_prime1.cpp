#include <iostream>
using namespace std;

template <int n, int k>
struct is_prime_helper {
    const static bool value = (n % k != 0) && is_prime_helper<n, k-1>::value;
};

template <int n>
struct is_prime_helper<n, 1> {
    const static bool value = true;
};

template <int n>
struct is_prime {
    const static bool value = is_prime_helper<n, n-1>::value;
};

/*
  is_prime_helper x k =
    if x mod k == 0:
      false
    else:
      if x == 1:
        true
      else:
        is_prime_helper x (k-1)

  is_prime x = is_prime_helper x (x-1)
 */
#include <cassert>

template <int p>
struct ModuloInt {
    int value;

    ModuloInt(int v): value(v) {}
    ModuloInt<p> operator+ (ModuloInt<p> o) {
        return ModuloInt((o.value + value) % p);
    }

    template <typename A = typename std::enable_if<is_prime<p>::value >::type >
    ModuloInt<p> invert() {
        //static_assert is_prime<p>::value, "attempting to invert a number modulo non-prime";
        return 0 /*dummy*/;
    }
};

int main() {
    cout << is_prime<13>::value << endl;
    ModuloInt<12> a = 5;
    a.invert();
}
