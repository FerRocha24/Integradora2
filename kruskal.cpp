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

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int px = find(x), py = find(y);
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
        if (uf.unite(u, v))
        {
            mst.emplace_back(u, v);
        }
    }

    return mst;
}