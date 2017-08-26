#include <vector>

template <typename T>
std::vector<T> mkvector(T arg) {
    std::vector<T> v;
    v.push_back(arg);
    return v;
}

template <typename T, typename... Args>
std::vector<T> mkvector(T arg, Args... rest) {
    std::vector<T> v = mkvector(rest...);
    v.push_back(arg);
    return v;
}

int main() {
    std::vector<int> v = mkvector(1, 2, 3);
}
