cmake_minimum_required(VERSION 4.0)

# Projenin adı ve sürümü
project(reverse_list VERSION 1.0)

# C++ standardını belirt
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Kaynak dosyaları belirt
set(SOURCES
    reverse_list.cpp
    linked_list.cpp
)

# Uygulama oluştur
add_executable(reverse_list ${SOURCES})