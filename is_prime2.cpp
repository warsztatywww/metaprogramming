
constexpr bool is_even(int b) {
    return b % 2 == 0;
}

constexpr bool is_prime(int b) {
    for (int i=2; i < b; i ++)
        if (b % i == 0)
            return false;
    return true;
}

template <typename T>
struct Foo {
    static_assert(false && sizeof(T), "error");
};

int main() {
    static_assert(is_prime(5), "oops!");
    static_assert(!is_prime(4), "oops!");
}
