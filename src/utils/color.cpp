#include <utils/color.hpp>
#include <utils/point.hpp>

void write_color(std::ostream& out, const Point3& p) {
    auto red = p.x();
    auto green = p.y();
    auto blue = p.z();

    int rbyte = int(255.999 * red);
    int gbyte = int(255.999 * green);
    int bbyte = int(255.999 * blue);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
