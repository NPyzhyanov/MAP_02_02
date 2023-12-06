#include <random>
#include <chrono>

#include "generate_random_value.h"

double generate_random_value(double min_value, double max_value)
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_real_distribution<double> dist(min_value, max_value);
    
    double result = dist(gen);
    return result;
}
