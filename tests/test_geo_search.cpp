#include <gtest/gtest.h>
#include "../geo_search.h"

TEST(GeoSearchTest, SingleCentral)
{
    std::vector<std::pair<int, int>> centrales = {{100, 100}};
    std::pair<int, int> nuevaCasa = {150, 150};

    auto closest = findClosestCentral(nuevaCasa, centrales);
    EXPECT_EQ(closest.first, 100);
    EXPECT_EQ(closest.second, 100);
}

TEST(GeoSearchTest, ExampleCase)
{
    std::vector<std::pair<int, int>> centrales = {
        {200, 500},
        {300, 100},
        {450, 150},
        {520, 480}};
    std::pair<int, int> nuevaCasa = {400, 300};

    auto closest = findClosestCentral(nuevaCasa, centrales);
    EXPECT_EQ(closest.first, 450);
    EXPECT_EQ(closest.second, 150);
}