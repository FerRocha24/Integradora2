
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

#include "kruskal.h"

class UnionFind
{
public:
    std::vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int Find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    bool Unite(int x, int y)
    {
        int px = Find(x), py = Find(y);
        if (px == py)
            return false;

        if (rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if (rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else
        {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

std::vector<std::pair<int, int>> kruskal(const std::vector<std::vector<int>> &graph)
{
    int n = graph.size();
    std::vector<std::tuple<int, int, int>> edges;

    // Crear lista de aristas
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] > 0)
            {
                edges.emplace_back(graph[i][j], i, j);
            }
        }
    }

    // Ordenar por peso
    std::sort(edges.begin(), edges.end());

    UnionFind uf(n);
    std::vector<std::pair<int, int>> mst;

    for (auto &[weight, u, v] : edges)
    {
        if (uf.Unite(u, v))
        {
            mst.emplace_back(u, v);
        }
    }

    return mst;
}
