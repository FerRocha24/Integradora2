#include <gtest/gtest.h>
#include "../tsp.h"

TEST(TSPTest, ThreeNodeComplete)
{
    std::vector<std::vector<int>> graph = {
        {0, 10, 15},
        {10, 0, 20},
        {15, 20, 0}};

    auto route = tsp(graph);
    EXPECT_EQ(route.size(), 3);
    EXPECT_EQ(route[0], 0);
}

TEST(TSPTest, FourNodeExample)
{
    std::vector<std::vector<int>> graph = {
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}};

    auto route = tsp(graph);
    EXPECT_EQ(route.size(), 4);
    EXPECT_EQ(route[0], 0);
}