#include "tsp.h"

std::vector<int> tsp(const std::vector<std::vector<int>> &graph)
{
    int n = graph.size();
    std::vector<int> cities;
    for (int i = 0; i < n; i++)
    {
        cities.push_back(i);
    }

    std::vector<int> bestRoute = cities;
    int minDistance = std::numeric_limits<int>::max();

    do
    {
        int currentDistance = 0;
        bool validRoute = true;

        for (int i = 0; i < n; i++)
        {
            int from = cities[i];
            int to = cities[(i + 1) % n];

            if (graph[from][to] == 0)
            {
                validRoute = false;
                break;
            }
            currentDistance += graph[from][to];
        }

        if (validRoute && currentDistance < minDistance)
        {
            minDistance = currentDistance;
            bestRoute = cities;
        }

    } while (std::next_permutation(cities.begin() + 1, cities.end()));

    return bestRoute;
}