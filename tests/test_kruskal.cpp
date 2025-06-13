#include <gtest/gtest.h>
#include "../kruskal.h"

TEST(KruskalTest, BasicGraph)
{
    std::vector<std::vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    auto mst = kruskal(graph);
    EXPECT_EQ(mst.size(), 4); // n-1 aristas
}

TEST(KruskalTest, TwoNodeGraph)
{
    std::vector<std::vector<int>> graph = {
        {0, 5},
        {5, 0}};

    auto mst = kruskal(graph);
    EXPECT_EQ(mst.size(), 1);
}