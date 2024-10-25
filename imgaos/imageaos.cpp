#include "imageaos.hpp"
#include <iostream>
#include <fstream>
#include <string>


image_aos::image_aos(const std::string &filename) {
  std::cout << "Procesando imagen AOS: " << filename << std::endl;
  std::ifstream input_file; 
  load_ppm_from_file(input_file, filename);
  
  std::string magic_number, width_s, height_s, color_max_s;
  std::uint16_t width, height, color_max; // he puesto uint16_t por poner ns si es el correcto. 

  // Comprobar que es archivo ppm (num mag = P6)
  input_file >> magic_number;
  
  // ver numero magico, borrar antes de entrega. 
  // std::cout << "numero magico: " << magic_number << std::endl;
    if (magic_number != "P6") { //funciona 
    std::cerr << "Archivo no es PPM" << std::endl; 
  }
  
  // Extraer resto de metadatos 
  input_file >> width_s;
  input_file >> height_s;
  input_file >> color_max_s;

  //Cast de los valores numericos en string a int
  width = std::stoi(width_s);
  height = std::stoi(height_s);
  color_max = std::stoi(color_max_s);
  
  //std::cout << "anchura: " << width << std::endl;
  //std::cout << "altura: " << height << std::endl;
  //std::cout << "color max: " << color_max << std::endl;
  
  if (color_max < 0 || color_max > 65535){
    std::cerr << "Error: Valor de color max incorrecto" << std::endl; 
  } else if (color_max < 256) {
    // caso con 1 byte por color RGB
  
  } else {
    // caso con 2 bytes por color RGB
    
  }
};

void image_aos::load_ppm_from_file(std::ifstream& file, const std::string& filepath) {
  
  // abrir archivo en modo binario
  //std::ifstream file(filepath, std::ios::binary);   
  file.open(filepath, std::ios::binary); 
  //Comprobar error en apertura fichero
  if (!file.is_open()) {
    std::cerr << "Error al abrir el archivo en modo binario" << std::endl;
    return; 
  }
};
