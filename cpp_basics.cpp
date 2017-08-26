
template <typename T, int i>
struct Vector {
    T array[i];

    Vector<T, i> operator+(Vector<T, i> other) {
        for (int j=0; j < i; j ++)
            array[j] += other.array[j];
    }
};

template <class T, int i>
T sum(Vector<T, i> v) {
    T r = 0;
    for (int j=0; j < i; j++)
        r += v[j];
    return r;
}

int main() {
    Vector<float, 3> xyz;
    auto xzy1 = xyz;
}
