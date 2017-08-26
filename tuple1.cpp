
template <typename... Args>
struct Tuple {};

template <typename First, typename... Args>
struct Tuple<First, Args...> {
    First item;
    Tuple<Args...> rest;

    Tuple(First arg, Args... argsrest):
        item(arg), rest(argsrest...) {}
};

/*
Tuple<int, int>

struct Tuple<int, int> {
  int item;
  Tuple<int> rest;
}

Tuple<int, int> t (1, 2);
  // item = 1
  // rest = Tuple<int>(2);
 */
