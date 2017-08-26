#include <cassert>

template <typename... T>
constexpr int countArgs(T... args) {
    // nie robić tego tak!!!
    return sizeof...(T);
}

int main() {
    assert(countArgs() == 0); // == 0
    assert(countArgs(1, 2, 3) == 3); // == 3
}
