
template <typename... Args>
struct Tuple {};

template <typename First, typename... Args>
struct Tuple<First, Args...> {
    First item;
    Tuple<Args...> rest;

    Tuple(First arg, Args... argsrest):
        item(arg), rest(argsrest...) {}
};

template <int num, typename T>
struct Get {
    static auto get(T tpl) {
        return Get::get<num-1>(tpl.rest);
    }
};

template <typename T>
struct Get<0, T> {
    static auto get(T tpl) {
        return tpl.item;
    }
};

template <int num, typename T>
auto get(T tpl) {
    return Get<num, T>::get(tpl);
}

int main() {
    Tuple<float, bool> a (1.0, false);
    float f = get<0>(a);
    bool b = get<1>(a);
}
