#pragma once

#include <random>
#include <ctime>

namespace math
{

namespace random
{

static void initSeed()
{
    std::srand(std::time(nullptr));
}

static double generate(int min, int max)
{
    double f = (double)std::rand() / RAND_MAX;
    return min + f * (max - min);
}

}; // namespace random
}; // namespace math