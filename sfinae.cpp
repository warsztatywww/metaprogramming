#include <iostream>
using namespace std;

template <typename A>
A frobificate(A x) {
    return x + 1;
}

string frobificate(string x) {
    return x + "1";
}

int main() {
    frobificate(std::string("s"));
}
