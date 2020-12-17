#pragma once

#include <random>
#include <ctime>

namespace math
{

namespace random
{

static void init_seed()
{
    std::srand(std::time(nullptr));
}

static double generate(double min, double max)
{
    double f = (double)std::rand() / RAND_MAX;
    return min + f * (max - min);
}

} // namespace random
} // namespace math