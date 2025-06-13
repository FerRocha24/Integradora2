cmake_minimum_required(VERSION 3.14)
project(GraphAlgorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configuración para cobertura de código
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

# Buscar Google Test
find_package(GTest REQUIRED)

# Archivos fuente
set(SOURCES
    kruskal.cpp
    tsp.cpp
    ford_fulkerson.cpp
    geo_search.cpp
)

# Crear biblioteca con las implementaciones
add_library(graph_algorithms ${SOURCES})

# Ejecutable principal
add_executable(main main.cpp)
target_link_libraries(main graph_algorithms)

# Pruebas unitarias
add_executable(tests
    tests/test_kruskal.cpp
    tests/test_tsp.cpp
    tests/test_ford_fulkerson.cpp
    tests/test_geo_search.cpp
)

target_link_libraries(tests 
    graph_algorithms 
    GTest::GTest 
    GTest::Main
)

# Configurar directorio de include
target_include_directories(graph_algorithms PUBLIC .)
target_include_directories(tests PUBLIC .)

# Habilitar testing
enable_testing()
add_test(NAME unit_tests COMMAND tests)