#include "imagesoa.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void image_soa::info(const string &filename) {
  cout << "Procesando imagen SOA: " << filename << endl;
  ifstream input_file; 
  load_ppm_from_file(input_file, filename);
  
  string magic_number, width_s, height_s, color_max_s;
  int width, height, color_max; // he puesto uint16_t por poner ns si es el correcto. 

  // Comprobar que es archivo ppm (num mag = P6)
  input_file >> magic_number;
  
  // ver numero magico, borrar antes de entrega. 
  // std::cout << "numero magico: " << magic_number << std::endl;
    if (magic_number != "P6") { //funciona 
    cerr << "Archivo no es PPM" << endl; 
  }
  
  // Extraer resto de metadatos 
  input_file >> width_s;
  input_file >> height_s;
  input_file >> color_max_s;

  //Cast de los valores numericos en string a int
  width = stoi(width_s);
  height = stoi(height_s);
  color_max = stoi(color_max_s);
 
  cout << "Número mágico: " << magic_number << endl;
  cout << "Anchura: " << width << endl;
  cout << "Altura: " << height << endl;
  cout << "Color máximo: " << color_max << endl;
  
  if (color_max < 0 || color_max > 65535){
    cerr << "Error: Valor de color max incorrecto" << endl; 
  } else if (color_max < 256) {
    // caso con 1 byte por color RGB
  
  } else {
    // caso con 2 bytes por color RGB
    
  }
};

void image_soa::load_ppm_from_file(ifstream& file, const string& filepath) {
  // abrir archivo en modo binario
  //std::ifstream file(filepath, std::ios::binary);   
  file.open(filepath, ios::binary); 
  //Comprobar error en apertura fichero
  if (!file.is_open()) {
    cerr << "Error al abrir el archivo en modo binario" << endl;
    return; 
  }
}
