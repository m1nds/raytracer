#include <iostream>

#include <utils/color.hpp>
#include <utils/point.hpp>
#include <geometry/vector.hpp>

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

            Point3 p = Point3(double(i) / (image_width-1),
                              double(j) / (image_height-1),
                              0);

            write_color(std::cout, p);
        }
    }

    std::clog << "\rDone.                 \n";
}
