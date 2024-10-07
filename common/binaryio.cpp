#include "binaryio.hpp"

template<typename T>
T read_binary(std::istream &input) {
    T value;
    input.read(reinterpret_cast<char *>(&value), sizeof(value));
    return value;
}

template<typename T>
void write_binary(std::ostream &output, T const &value) {
    output.write(reinterpret_cast<const char *>(&value), sizeof(value));
}

