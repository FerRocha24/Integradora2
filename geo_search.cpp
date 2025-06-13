#include "geo_search.h"

std::pair<int, int> findClosestCentral(std::pair<int, int> nuevaCasa, const std::vector<std::pair<int, int>> &centrales)
{
    if (centrales.empty())
    {
        return {0, 0};
    }

    double minDistance = std::numeric_limits<double>::max();
    std::pair<int, int> closest = centrales[0];

    for (const auto &central : centrales)
    {
        double dx = nuevaCasa.first - central.first;
        double dy = nuevaCasa.second - central.second;
        double distance = std::sqrt(dx * dx + dy * dy);

        if (distance < minDistance)
        {
            minDistance = distance;
            closest = central;
        }
    }

    return closest;
}