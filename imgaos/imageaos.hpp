#ifndef IMAGEAOS_HPP
#define IMAGEAOS_HPP

#include <string>
#include <vector>
#include <cstdint>

// estructura para cada pixel, con sus valores rgb.
struct Pixel {  
  uint16_t r;
  uint16_t g;
  uint16_t b;
}; 


// clase que representa la imagen
class image_aos {
public:
  // constructor que recibe el path de la imagen
  image_aos(const std::string &filename);
  
  // metodo para leer la imagen ppm 
  void load_ppm_from_file(std::ifstream& file, const std::string& filepath);
 
  // metodo que extrae los metadatos de la imagen
  void extract_metadata() const;

private:
  // definicion de altura, anchura y valor max de color
  int height;
  int width;
  int max_color;
  std::vector<Pixel> pixels; // vector de pixeles de tipo struct Pixel
  
  
};


#endif
