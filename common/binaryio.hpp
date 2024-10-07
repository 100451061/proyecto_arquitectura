#ifndef BINARYIO_HPP
#define BINARYIO_HPP

#include <iostream>
#include <fstream>

template <typename T>
T read_binary(std::istream & input);

template <typename T>
void write_binary(std::ostream & output, T const & value);

#endif
