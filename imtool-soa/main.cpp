#include "../imgsoa/imagesoa.hpp"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
   if (argc < 4) {
    cerr << "Error: invalid number of arguments: " << (argc - 1) << endl;
    return -1; 
  } 
  
  string option = argv[3];

  //INFO
  if (option == "info") {
    if (argc > 4) {
      cerr << "Error: invalid extra argument for info: " << argv[4] << endl;
      return -1;
    }
    // Llamar funcion AOS
    image_soa image_processor;
    image_processor.info(string(argv[1]));
  }
  
  // MAX LEVEL
  if (option == "maxlevel"){
    // comprobar argumentos extra:
    if (argc != 5) {
      int extra_args = argc - 4;
      cerr << "Error: invalid number of extra arguments for maxlevel: " << extra_args << endl;
      return -1; 
    }
    // comprobar valor 4o argumento
    try {
      int maxlevel = stoi(argv[4]); // static cast de str a int. 
      if (maxlevel < 0 || maxlevel > 65535){ 
        cerr << "Error: invalid maxlevel: " << maxlevel << endl; 
      }
    } catch (const invalid_argument& e) {
      cerr << "Error: invalid maxlevel: " << argv[4] << endl;
    }
    // llamar a MAX LVL aquí  
  } 

  // RESIZE
  if (option == "resize"){
    // comprobar que son exactamente 5 (argc = 6): 
    if (argc != 6) {
      int extra_args = argc - 4;
      cerr << "Error: invalid number of extra arguments for resize: " << extra_args << endl;
      return -1; 
    }
    try {
      int new_width = stoi(argv[4]);
      if (new_width < 0){
        cerr << "Error: ivalid new width for resize: " << new_width << endl;
        return -1;
      }
    } catch (const invalid_argument& e) {
      cerr << "Error: ivalid new width for resize: " << argv[4] << endl;
      return -1; 
    }
    try {
      int new_height = stoi(argv[5]);
      if (new_height < 0){
        cerr << "Error: ivalid new height for resize: " << new_height << endl;
        return -1;
      }
    } catch (const invalid_argument& e) {
      cerr << "Error: ivalid new height for resize: " << argv[5] << endl;
      return -1; 
    }
    // llamar a RESIZE aquí
  }

  // CUTFREQ
  if (option == "cutfreq"){
    if (argc != 5) {
      int extra_args = argc - 4;
      cerr << "Error: invalid number of extra arguments for cutfreq: " << extra_args << endl;
      return -1; 
    }
    try {
      int cutfreq = stoi(argv[4]);
      if (cutfreq < 0){
        cerr << "Error: Invalid cutfreq: " << cutfreq << endl;
      }
    } catch (const invalid_argument& e) {
      cerr << "Error: Invalid cutfreq: " << argv[4] << endl;
    }
  } 
  
  // COMPRESS 
  if (option == "compress"){
    
  } 
  return 0;

}
