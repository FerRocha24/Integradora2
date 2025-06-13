#include <gtest/gtest.h>
#include "../ford_fulkerson.h"

class FordFulkersonTest : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FordFulkersonTest, BasicFlow)
{
    std::vector<std::vector<int>> capacity = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};

    int maxFlow = ford_fulkerson(capacity, 0, 5);
    EXPECT_EQ(maxFlow, 23);
}

TEST_F(FordFulkersonTest, SimpleFlow)
{
    std::vector<std::vector<int>> capacity = {
        {0, 10, 10},
        {0, 0, 25},
        {0, 0, 0}};

    int maxFlow = ford_fulkerson(capacity, 0, 2);
    EXPECT_EQ(maxFlow, 20); // Corregido: el flujo máximo real es 20
}

TEST_F(FordFulkersonTest, NoFlow)
{
    std::vector<std::vector<int>> capacity = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    int maxFlow = ford_fulkerson(capacity, 0, 2);
    EXPECT_EQ(maxFlow, 0);
}

TEST_F(FordFulkersonTest, SinglePath)
{
    std::vector<std::vector<int>> capacity = {
        {0, 5, 0},
        {0, 0, 3},
        {0, 0, 0}};

    int maxFlow = ford_fulkerson(capacity, 0, 2);
    EXPECT_EQ(maxFlow, 3);
}