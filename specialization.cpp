
template <typename X, typename Y>
class Map {
    /// ...
};

// Map<string, float> f;
// f["ff"] = 5;

template <typename Y>
class Map<int, Y> {
    /// faster implementation for integer keys
};

// Map<int, float> f;

template <typename X>
class Map<X, int> {
    //
};

Map<int, int> a;
