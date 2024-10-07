#include "progargs.hpp"
#include <iostream>

std::string parse_operation(int argc, char* argv[]) {
    if (argc < 3) {
        throw std::invalid_argument("Número de argumentos insuficiente");
    }
    return argv[3]; // La operación es el tercer argumento
}

void print_image_metadata(const std::string& filename) {
    std::cout << "Mostrando metadatos para " << filename << std::endl;
    // Aquí agregarías el código para mostrar los metadatos reales
}
