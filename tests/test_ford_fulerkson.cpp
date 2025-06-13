#include <gtest/gtest.h>
#include "../ford_fulkerson.h"

TEST(FordFulkersonTest, BasicFlow)
{
    std::vector<std::vector<int>> capacity = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};

    int maxFlow = fordFulkerson(capacity, 0, 5);
    EXPECT_EQ(maxFlow, 23);
}

TEST(FordFulkersonTest, SimpleFlow)
{
    std::vector<std::vector<int>> capacity = {
        {0, 10, 10},
        {0, 0, 25},
        {0, 0, 0}};

    int maxFlow = fordFulkerson(capacity, 0, 2);
    EXPECT_EQ(maxFlow, 10);
}