#ifndef PROGARGS_HPP
#define PROGARGS_HPP

#include <string>

std::string parse_operation(int argc, char* argv[]);
void print_image_metadata(const std::string& filename);

#endif
