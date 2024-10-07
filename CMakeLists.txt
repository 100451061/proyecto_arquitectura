cmake_minimum_required(VERSION 3.26)
project(imtool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Configurar clang-tidy
set(CMAKE_CXX_CLANG_TIDY clang-tidy)

# Añadir subdirectorios
add_subdirectory(common)
add_subdirectory(imgaos)
add_subdirectory(imgsoa)

# Crear los ejecutables
add_executable(imtool-soa main_soa.cpp)
add_executable(imtool-aos main_aos.cpp)

# Enlazar las bibliotecas
target_link_libraries(imtool-soa imgsoa common)
target_link_libraries(imtool-aos imgaos common)
