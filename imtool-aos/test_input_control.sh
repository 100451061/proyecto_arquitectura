#!/bin/bash
touch photo.ppm
touch out.ppm

# compilar
g++ main.cpp ../imgaos/imageaos.cpp -o imtool

# Test numero de argumentos
./imtool
./imtool photo.ppm
./imtool photo.ppm out.ppm

# Test invalid option parameter
./imtool photo.ppm out.ppm copy

# Test info arguments
./imtool photo.ppm out.ppm info 100

# Test maxlevel 
./imtool photo.ppm out.ppm maxlevel 
./imtool photo.ppm out.ppm maxlevel 100 100
./imtool photo.ppm out.ppm maxlevel -1
./imtool photo.ppm out.ppm maxlevel 70000
./imtool photo.ppm out.ppm maxlevel copy

# Test resize
./imtool photo.ppm out.ppm resize
./imtool photo.ppm out.ppm resize 100
./imtool photo.ppm out.ppm resize 100 200 300 
./imtool photo.ppm out.ppm resize -100 200
./imtool photo.ppm out.ppm resize 100 -200
./imtool photo.ppm out.ppm resize max 200
./imtool photo.ppm out.ppm resize 100 max

# Test cutfreq 
./imtool photo.ppm out.ppm cutfreq
./imtool photo.ppm out.ppm cutfreq 100 100 
./imtool photo.ppm out.ppm cutfreq -1 
./imtool photo.ppm out.ppm cutfreq copy


# Clean up dir
rm photo.ppm out.ppm
