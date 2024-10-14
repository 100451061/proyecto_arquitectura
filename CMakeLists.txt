cmake_minimum_required(VERSION 3.26)
project(imtool LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# Set compiler options
add_compile_options(−Wall −Wextra −Werror −pedantic −pedantic−errors −Wconversion −Wsign−conversion)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} −march=native")
# Enable GoogleTest Library
include(FetchContent)
FetchContent_Declare(
googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)
# Enable GSL Library
FetchContent_Declare(GSL
GIT_REPOSITORY "https://github.com/microsoft/GSL"
GIT_TAG v4.0.0
GIT_SHALLOW ON
)
FetchContent_MakeAvailable(GSL)
# Run clang−tidy on the whole source tree
# Note this will slow down compilation.
# You may temporarily disable but do not forget to enable again.
set(CMAKE_CXX_CLANG_TIDY clang−tidy;
−format−style=file;
−header−filter=.;)
# All includes relative to source tree root.
include_directories (PUBLIC .)
# Process cmake from sim and fluid directories
add_subdirectory(common)
add_subdirectory(imgaos)
add_subdirectory(imgsoa)
add_subdirectory(imtool-aos)
add_subdirectory(imtool-soa)
# Unit tests and functional tests
enable_testing()
add_subdirectory(utest-common)
add_subdirectory(utest-imgaos)
add_subdirectory(utest-imgsoa)
add_subdirectory(ftest-aos)
add_subdirectory(ftest-soa)
