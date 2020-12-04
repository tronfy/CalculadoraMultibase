cmake_minimum_required(VERSION 3.17)
project(CalculadoraMultibase)

set(CMAKE_CXX_STANDARD 14)

add_executable(CalculadoraMultibase main.cpp SomadoraUnica.cpp SomadoraUnica.h Operacao.cpp Operacao.h Algarismos.cpp Algarismos.h Utils.cpp Utils.h Calculator.cpp Calculator.h Somadora.cpp Somadora.h Multiplicadora.cpp Multiplicadora.h)