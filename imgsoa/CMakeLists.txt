# Necesitará cambios futuros, pone en el enunciado que es similar al imageaos/CMakeLists.txt, lo he COPIADO.

# Add to this list all files related to imgaos library
add_library(imgsoa
image.cpp
other1.cpp
other2.cpp
)
# Use this line only if you have dependencies from this library to GSL
target_link_libraries (imgsoa PRIVATE common Microsoft.GSL::GSL)

