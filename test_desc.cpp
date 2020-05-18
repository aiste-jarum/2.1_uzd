#define CATCH_CONFIG_MAIN
#include "catch.hpp"

double middle (double avg, int egz)
{
    return avg*0.4+egz*0.6;
}

double average (std::vector<int> i)
{
    double sum = 0;
    for (int j = 0; j < i.size(); j++) sum+=i.at(j);
    return sum/i.size();
}

TEST_CASE() {
    REQUIRE (middle(10, 5) == 7);
}
TEST_CASE() {
    std::vector<int> x;
    x.push_back(5);
    x.push_back(10);
    x.push_back(2);
    x.push_back(3);
    x.push_back(8);
    REQUIRE (average(x) == 5.6);
}

TEST_CASE () {
    int a = 10;
    for (int i = 0; i < 4; i++) a *= 10;
    REQUIRE (a == 100000);
}

int vid (double v)
{
    if (v < 5.0) return 0;
    else return 1;
}

TEST_CASE () {
    int boo = vid(5.0);
    REQUIRE (boo == 1);
    boo = vid(3.2);
    REQUIRE (boo == 0);
    boo = vid(9.9);
    REQUIRE (boo == 1);
}
