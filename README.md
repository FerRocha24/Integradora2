# Graph Algorithms Project

Este proyecto implementa algoritmos de grafos para ayudar a una empresa de servicios de Internet con:

1. **Algoritmo de Kruskal**: Para encontrar el árbol de expansión mínima y optimizar el cableado de fibra óptica
2. **Problema del Viajante (TSP)**: Para encontrar la ruta más corta que visite todas las colonias
3. **Algoritmo de Ford-Fulkerson**: Para calcular el flujo máximo de información
4. **Búsqueda Geográfica**: Para encontrar la central más cercana a una nueva contratación

## Estructura del Proyecto

```
├── src/
│   ├── kruskal.h/cpp        # Implementación del algoritmo de Kruskal
│   ├── tsp.h/cpp            # Implementación del TSP
│   ├── ford_fulkerson.h/cpp # Implementación de Ford-Fulkerson
│   ├── geo_search.h/cpp     # Búsqueda geográfica
│   └── main.cpp             # Programa principal
├── tests/                   # Pruebas unitarias
├── .github/workflows/       # GitHub Actions CI/CD
├── CMakeLists.txt          # Configuración de CMake
└── sonar-project.properties # Configuración de SonarQube
```

## Compilación

### Requisitos

- CMake 3.14+
- GCC/Clang con soporte C++17
- Google Test
- lcov (para cobertura de código)

### Compilar el proyecto

```bash
# Configurar el build
cmake -B build -DCMAKE_BUILD_TYPE=Debug

# Compilar
cmake --build build

# Ejecutar el programa principal
./build/main
```

### Ejecutar pruebas

```bash
cd build
ctest --output-on-failure
```

### Generar reporte de cobertura

```bash
cd build
lcov --capture --directory . --output-file coverage.info
lcov --remove coverage.info '/usr/*' --output-file coverage.info
genhtml coverage.info --output-directory coverage_html
```

## Formato de Entrada

```
N
[Matriz de dist
```
