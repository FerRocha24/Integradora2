
/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

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
