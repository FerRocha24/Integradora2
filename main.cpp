#include <iostream>
#include <iomanip>
#include "kruskal.h"
#include "tsp.h"
#include "ford_fulkerson.h"
#include "geo_search.h"

int main()
{
    int N;
    std::cin >> N;

    // Leer matriz de distancias
    std::vector<std::vector<int>> distanceMatrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> distanceMatrix[i][j];
        }
    }

    // Leer matriz de capacidades
    std::vector<std::vector<int>> capacityMatrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> capacityMatrix[i][j];
        }
    }

    // Leer ubicaciones de centrales
    std::vector<std::pair<int, int>> centrales;
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        centrales.emplace_back(x, y);
    }

    // Leer nueva ubicación
    int xNuevo, yNuevo;
    std::cin >> xNuevo >> yNuevo;

    // 1. Algoritmo de Kruskal (MST)
    std::cout << "1." << std::endl;
    auto mst = kruskal(distanceMatrix);
    for (const auto &edge : mst)
    {
        std::cout << "(" << char('A' + edge.first) << ", "
                  << char('A' + edge.second) << ")" << std::endl;
    }

    // 2. TSP (Traveling Salesman Problem)
    std::cout << std::endl
              << "2." << std::endl;
    auto tspRoute = tsp(distanceMatrix);
    for (size_t i = 0; i < tspRoute.size(); ++i)
    {
        std::cout << char('A' + tspRoute[i]);
        if (i < tspRoute.size() - 1)
            std::cout << " ";
    }
    std::cout << " " << char('A' + tspRoute[0]) << std::endl;

    // 3. Ford-Fulkerson (Flujo máximo)
    std::cout << std::endl
              << "3." << std::endl;
    int maxFlowValue = ford_fulkerson(capacityMatrix, 0, N - 1);
    std::cout << maxFlowValue << std::endl;

    // 4. Búsqueda de central más cercana
    std::cout << std::endl
              << "4." << std::endl;
    auto closest = findClosestCentral({xNuevo, yNuevo}, centrales);
    std::cout << "(" << closest.first << ", " << closest.second << ")" << std::endl;

    return 0;
}