#include "ford_fulkerson.h"

bool bfs(std::vector<std::vector<int>> &rGraph, int s, int t, std::vector<int> &parent)
{
    int V = rGraph.size();
    std::vector<bool> visited(V, false);
    std::queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(std::vector<std::vector<int>> capacity, int s, int t)
{
    int V = capacity.size();
    std::vector<std::vector<int>> rGraph = capacity;
    std::vector<int> parent(V);
    int maxFlowValue = 0;

    while (bfs(rGraph, s, t, parent))
    {
        int pathFlow = INT_MAX;

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            pathFlow = std::min(pathFlow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlowValue += pathFlow;
    }

    return maxFlowValue;
}