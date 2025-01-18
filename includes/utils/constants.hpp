#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <limits>

// Constants
constexpr double INF = std::numeric_limits<double>::infinity();
constexpr double PI = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
}

#endif
