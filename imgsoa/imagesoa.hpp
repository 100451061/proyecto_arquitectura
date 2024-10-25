#ifndef IMAGESOA_HPP
#define IMAGESOA_HPP

#include <string>

// void process_image_soa(const std::string& filename);

// clase que representa la imagen
class image_soa {
    public:
      // constructor que recibe el path de la imagen
      void info(const std::string &filename);
      
      // metodo para leer la imagen ppm 
      void load_ppm_from_file(std::ifstream& file, const std::string& filepath);
     
      // metodo que extrae los metadatos de la imagen
      void extract_metadata() const;

    private:
      // definicion de altura, anchura y valor max de color
      //int height;
      //int width;
      //int max_color;
      //std::vector<Pixel> pixels; // vector de pixeles de tipo struct Pixel
      
      
};

#endif
