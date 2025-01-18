#include <utils/color.hpp>
#include <utils/point.hpp>
#include <utils/interval.hpp>

void write_color(std::ostream& out, const Point3& p) {
    static const Interval intensity(0.000, 0.999);

    auto red = p.x();
    auto green = p.y();
    auto blue = p.z();

    int rbyte = int(256 * intensity.clamp(red));
    int gbyte = int(256 * intensity.clamp(green));
    int bbyte = int(256 * intensity.clamp(blue));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
