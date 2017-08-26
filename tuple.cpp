
template <typename... Args>
class Tuple {};


template <typename First, typename... Args>
struct Tuple<First, Args...> {
    First item;
    Tuple<Args...> rest;

    using Rest = Tuple<Args...>;

    Tuple(First arg, Args... argsrest): item(arg), rest(argsrest...) {}
};


template <int num, typename T>
struct Get {
    static decltype(auto) get(T tpl) {
        return Get<num-1, typename T::Rest>::get(tpl.rest);
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
    Tuple<float, bool>::Rest b(false);
    get<0>(a);
    get<1>(a);
}
