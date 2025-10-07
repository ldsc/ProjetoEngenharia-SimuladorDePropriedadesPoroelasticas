cmake_minimum_required(VERSION 3.15)

# Nome do projeto e padrão C++
project(PoreElasticCalculator VERSION 1.0 LANGUAGES CXX)

# C++17 ou superior
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Diretórios
include_directories(include)

# Lista de fontes
file(GLOB_RECURSE SOURCES
    src/*.cpp
    include/*.h
    main.cpp
)

# Executável principal
add_executable(${PROJECT_NAME} ${SOURCES})

# Opções para warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-unused-parameter)
elseif (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
endif()
