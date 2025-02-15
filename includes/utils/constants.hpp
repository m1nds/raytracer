#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <limits>
#include <random>

// Constants
constexpr double INF = std::numeric_limits<double>::infinity();
constexpr double PI = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    return min + (max-min)*random_double();
}

inline double linear_to_gamma(double linear_component) {
    return (linear_component > 0) ? std::sqrt(linear_component) : 0;
}

#endif
