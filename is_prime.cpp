#include <iostream>
using namespace std;

/*
template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };
 */

template <int p, int i>
struct check_prime {
    static const bool value = (p % i != 0) && (check_prime<p, i - 1>::value);
};

template <int p>
struct check_prime<p, 1> {
    static const bool value = true;
};

template <int p>
struct is_prime {
    static const bool value = check_prime<p, p - 1>::value;
};

template <int p>
struct ModuloInt {
    int value;

    ModuloInt(int v): value(p) {}
    ModuloInt<p> operator+ (ModuloInt<p> o) {
        return ModuloInt((o.value + value) % p);
    }

    template <typename = typename std::enable_if<is_prime<p>::value >::type >
    ModuloInt<p> invert() {
        return 0 /*dummy*/;
    }
};

int main() {
    cout << is_prime<12>::value << endl;
    ModuloInt<12> v = 13;
    v = v + 9;
    v.invert();
}
