#include <vector>

template <template <typename> typename X>
X<int> generateInts(int x) {
    X<int> v;
    for (int i=0; i < x; i ++) v.push_back(i);
    return v;
}

int main() {
    generateInts<std::vector>(10);
}
