#include <iostream>
#include "kruskal.h"
#include "tsp.h"
#include "ford_fulkerson.h"
#include "geo_search.h"

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> distanceMatrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            std::cin >> distanceMatrix[i][j];

    std::vector<std::vector<int>> capacityMatrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            std::cin >> capacityMatrix[i][j];

    std::vector<std::pair<int, int>> centrales;
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        centrales.emplace_back(x, y);
    }

    int xNuevo, yNuevo;
    std::cin >> xNuevo >> yNuevo;

    std::cout << "1.\n";
    auto mst = kruskal(distanceMatrix);
    for (auto &[a, b] : mst)
        std::cout << "(" << char('A' + a) << ", " << char('A' + b) << ")\n";

    std::cout << "\n2.\n";
    auto tspRoute = tsp(distanceMatrix);
    for (int idx : tspRoute)
        std::cout << char('A' + idx) << " ";
    std::cout << char('A' + tspRoute.front()) << "\n";

    std::cout << "\n3.\n";
    int maxFlowValue = fordFulkerson(capacityMatrix, 0, N - 1);
    std::cout << maxFlowValue << "\n";

    std::cout << "\n4.\n";
    auto closest = findClosestCentral({xNuevo, yNuevo}, centrales);
    std::cout << "(" << closest.first << ", " << closest.second << ")\n";

    return 0;
}
