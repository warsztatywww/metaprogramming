#include <cmath>

template <typename T>
double sum(T t) {
  return t;
}

template <typename T, typename... Rest>
double sum(T t, Rest... rest) {
  return t + sum(rest...);
}


template <typename T>
double sum_sq(T t) {
    return t * t;
}

template <typename T, typename... Rest>
double sum_sq(T t, Rest... rest) {
    return t * t + sum_sq(rest...);
}

template <typename... Rest>
double vector_length2(Rest... rest) {
    return sqrt(sum_sq<Rest...>(rest...));
}

double sq(double v) {
    return v * v;
}

template <typename... Args>
double vector_length(Args... args) {
    return sqrt(sum(sq(args)...));
}

int main() {
    sum<double>(2);
    sum(2.0);

    sum<double, double, double>(1.2, 2.0, 3.0);
    sum(1.2, 2.0, 3.0);

    vector_length(1.2, 2.0, 3.0);
}
