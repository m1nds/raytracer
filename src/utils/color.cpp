#include <utils/color.hpp>
#include <utils/constants.hpp>
#include <utils/point.hpp>
#include <utils/interval.hpp>

void write_color(std::ostream& out, const Point3& p) {
    static const Interval intensity(0.000, 0.999);

    auto red = linear_to_gamma(p.x());
    auto green = linear_to_gamma(p.y());
    auto blue = linear_to_gamma(p.z());

    int rbyte = int(256 * intensity.clamp(red));
    int gbyte = int(256 * intensity.clamp(green));
    int bbyte = int(256 * intensity.clamp(blue));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
